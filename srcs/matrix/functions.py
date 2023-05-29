# ~~~~~~~~~~~~~~~~~~~~~~~~~~ #
# Linear Combination         #
# ~~~~~~~~~~~~~~~~~~~~~~~~~~ #
# Max Time Complexity: O(n)  #
# Max Space Complexity: O(n) #
# ~~~~~~~~~~~~~~~~~~~~~~~~~~ #

def linear_combination(vectors, coeffs):

    """
        Returns the linear combination of a list of vectors and
        a list of coefficients

        Args:
            vectors: A list of vectors
            coeffs: A list of coefficients

        Raises:
            TypeError: If vectors is not a list
            TypeError: If coeffs is not a list
            ValueError: If vectors is empty
            ValueError: If coeffs is empty
            ValueError: If vectors and coeffs are not of the same size
            TypeError: If all elements of vectors are not of type Vector
            TypeError: If all elements of coeffs are not of number type
            ValueError: If all vectors are not of the same size

        Returns:
            A vector
    """

    if not isinstance(vectors, list):
        raise TypeError("Vectors must be a list")
    if not isinstance(coeffs, list):
        raise TypeError("Coeffs must be a list")
    if len(vectors) == 0:
        raise ValueError("Vectors must not be empty")
    if len(coeffs) == 0:
        raise ValueError("Coeffs must not be empty")
    if len(vectors) != len(coeffs):
        raise ValueError("Vectors and Coeffs must be of the same size")

    first_vector_shape = vectors[0].shape

    for i in range(len(vectors)):
        if not isinstance(vectors[i], Vector):
            raise TypeError("All elements of vectors must be a Vector")
        if not isinstance(coeffs[i], (int, float)):
            raise TypeError("All elements of coeffs must be a number")
        if vectors[i].shape != first_vector_shape:
            raise ValueError("All vectors must be of the same size")

    result = Vector(shape=first_vector_shape)
    for i in range(len(vectors)):
        result.data = [
            float(Decimal.fma(Decimal(coeffs[i]), Decimal(v), Decimal(r)))
            for v, r in zip(vectors[i].data, result.data)
        ]

    return result


# ~~~~~~~~~~~~~~~~~~~~~~~~~~ #
# Linear Interpolation       #
# ~~~~~~~~~~~~~~~~~~~~~~~~~~ #
# Max Time Complexity: O(n)  #
# Max Space Complexity: O(n) #
# ~~~~~~~~~~~~~~~~~~~~~~~~~~ #

def lerp(u, v, t):
    """
        Returns the linear interpolation between two vectors

        Args:
            u: A vector
            v: A vector
            t: A number

        Raises:
            TypeError: If u is not a Vector
            TypeError: If v is not a Vector
            TypeError: If t is not a number
            ValueError: If u and v are not of the same size
    """

    if not isinstance(u, Vector):
        raise TypeError("U must be a Vector")
    if not isinstance(v, Vector):
        raise TypeError("V must be a Vector")
    if not isinstance(t, (int, float)):
        raise TypeError("T must be a number")
    if u.shape != v.shape:
        raise ValueError("U and V must be of the same size")

    return Vector.linear_combination([u, v], [1 - t, t])
