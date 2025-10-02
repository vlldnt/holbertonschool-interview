#!/usr/bin/python3
"""
UTF-8 Validation Module
This module provides a function to validate whether a given data set
represents a valid UTF-8 encoding
"""


def validUTF8(data):
    """
    Determine if a given data set represents a valid UTF-8 encoding
    """
    # Track the number of continuation bytes expected
    n_bytes = 0

    # Iterate through each byte in the data
    for b in data:
        b &= 0xFF

        # If we're not expecting continuation bytes
        if n_bytes == 0:
            # Check if this is a 2-byte character (starts with 110)
            if b >> 5 == 0b110:
                n_bytes = 1  # Expect 1 continuation byte
            # Check if this is a 3-byte character (starts with 1110)
            elif b >> 4 == 0b1110:
                n_bytes = 2  # Expect 2 continuation bytes
            # Check if this is a 4-byte character (starts with 11110)
            elif b >> 3 == 0b11110:
                n_bytes = 3  # Expect 3 continuation bytes
            # Check if this is a 1-byte character (starts with 0)
            elif b >> 7 == 0:
                continue  # Valid 1-byte char, move to next byte
            # Invalid start byte
            else:
                return False
        # If we're expecting continuation bytes
        else:
            # Check if this byte is a valid continuation byte (starts with 10)
            if b >> 6 != 0b10:
                return False  # Invalid continuation byte
            # Decrement the count of expected continuation bytes
            n_bytes -= 1

    # Valid UTF-8 if all continuation bytes have been processed
    return n_bytes == 0
