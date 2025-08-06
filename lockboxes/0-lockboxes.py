#!/usr/bin/python3
''' method that determines if all the boxes can be opened.'''


def canUnlockAll(boxes):
    if not boxes:
        return False

    opened = {0}
    keys = boxes[0]

    while keys:
        key = keys.pop()
        if key not in opened and key < len(boxes):
            opened.add(key)
            for k in boxes[key]:
                if k not in opened:
                    keys.append(k)

    return len(boxes) == len(opened)
