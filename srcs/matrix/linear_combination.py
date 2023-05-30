import vector
from decimal import Decimal


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
        if not isinstance(vectors[i], vector.Vector):
            raise TypeError("All elements of vectors must be a Vector")
        if not isinstance(coeffs[i], (int, float)):
            raise TypeError("All elements of coeffs must be a number")
        if vectors[i].shape != first_vector_shape:
            raise ValueError("All vectors must be of the same size")

    result = vector.Vector(shape=first_vector_shape)
    for i in range(len(vectors)):
        result.data = [
            float(Decimal.fma(Decimal(coeffs[i]), Decimal(v), Decimal(r)))
            for v, r in zip(vectors[i].data, result.data)
        ]

    return result


if __name__ == "__main__":
    v1 = vector.Vector([1, 2, 3])
    v2 = vector.Vector([4, 5, 6])
    vectors = [v1, v2]
    coeffs = [2, 3]
    result = linear_combination(vectors, coeffs)
    print(result)
