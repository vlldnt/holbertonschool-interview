#!/usr/bin/env python3
"""Module to count keywords in Reddit hot article titles"""
import requests


def count_words(subreddit, word_list, after=None, word_count=None):
    """Count and print sorted keyword occurrences from subreddit hot posts"""
    # Initialize word count dictionary on first call
    if word_count is None:
        word_count = {}
        for word in word_list:
            lower_word = word.lower()
            if lower_word not in word_count:
                word_count[lower_word] = 0

    # Build request
    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    headers = {"User-Agent": "linux:count_words:v1.0 (by /u/holberton)"}
    params = {"limit": 100}
    if after:
        params["after"] = after

    # Make API request (no redirects for invalid subreddits)
    try:
        response = requests.get(url, headers=headers, params=params,
                                allow_redirects=False)
    except Exception:
        return

    if response.status_code != 200:
        return

    try:
        data = response.json()
    except Exception:
        return

    # Count keywords in each post title
    posts = data.get("data", {}).get("children", [])
    for post in posts:
        title = post.get("data", {}).get("title", "")
        title_words = title.lower().split()

        for title_word in title_words:
            # Strip non-alpha chars from ends
            start, end = 0, len(title_word)
            while start < end and not title_word[start].isalpha():
                start += 1
            while end > start and not title_word[end - 1].isalpha():
                end -= 1
            cleaned_word = title_word[start:end]

            # Count only pure alphabetic matches
            if cleaned_word.isalpha() and cleaned_word in word_count:
                word_count[cleaned_word] += 1

    # Recurse for next page or print results
    next_page = data.get("data", {}).get("after")
    if next_page:
        return count_words(subreddit, word_list, next_page, word_count)

    # Print results sorted by count desc, then alpha asc
    results = [(w, c) for w, c in word_count.items() if c > 0]
    results.sort(key=lambda x: (-x[1], x[0]))
    for word, count in results:
        print("{}: {}".format(word, count))
