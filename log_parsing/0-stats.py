#!/usr/bin/python3
"""Parse logs and return error count and file size"""

import sys

STATUS_CODES = [200, 301, 400, 401, 403, 404, 405, 500]


def parse_line(line):
    try:
        parts = line.strip().split()
        if len(parts) < 2:
            return None, None
        status = int(parts[-2])
        size = int(parts[-1])
        return status, size
    except (IndexError, ValueError):
        return None, None


def print_stats(total, count):
    print(f"File size: {total}")
    for code in sorted(STATUS_CODES):
        if code in count:
            print(f"{code}: {count[code]}")


def stats():
    total = 0
    count = {}
    line_number = 0

    try:
        for line in sys.stdin:
            status, size = parse_line(line)
            if status is None or size is None:
                continue

            if status in STATUS_CODES:
                count[status] = count.get(status, 0) + 1
                total += size
                line_number += 1

            if line_number % 10 == 0:
                print_stats(total, count)

    except KeyboardInterrupt:
        pass

    finally:
        print_stats(total, count)


if __name__ == '__main__':
    stats()
