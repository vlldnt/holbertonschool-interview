#!/usr/bin/python3
'''
    Calculate the minimum number of operations to reach exactly n characters
    using only Copy All and Paste operations.

    The function finds the smallest sequence of factors that multiply to n,
    where each factor represents a Copy All followed by (factor - 1) Paste operations.

    Args:
        n (int): The target number of characters.

    Returns:
        int: The minimum number of operations required to reach n characters.
             Returns 0 if n is less than 2 (no operations needed).
    '''


def minOperations(n):
    ''' Calculate the minimum number of operations to reach exactly n characters 
    using only Copy All and Paste operations '''
    # Copy n to number for processing
    number = n

    # If n is less than 2, no operations are needed
    if number < 2:
        return 0

    # Total number of operations
    operations = 0

    # While until the number equal 1
    while number > 1:

        # Start checking divisors from 2
        div = 2

        # Find the smallest divisor of number
        while number % div != 0:

            # Increment divisor
            div += 1

        # Add divisor to operations
        operations += div

        # Divide number by the found divisor
        number //= div

    # Return the total operations
    return operations
