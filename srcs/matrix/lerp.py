import vector
import linear_combination


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

    if not isinstance(u, vector.Vector):
        raise TypeError("U must be a Vector")
    if not isinstance(v, vector.Vector):
        raise TypeError("V must be a Vector")
    if not isinstance(t, (int, float)):
        raise TypeError("T must be a number")
    if u.shape != v.shape:
        raise ValueError("U and V must be of the same size")

    return linear_combination.linear_combination([u, v], [1 - t, t])


if __name__ == "__main__":
    v1 = vector.Vector([1, 2, 3])
    v2 = vector.Vector([4, 5, 6])
    vectors = [v1, v2]
    coeffs = [2, 3]
    result = lerp(v1, v2, 42.)
    print(result)
