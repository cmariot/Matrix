import matrix


class Vector:

    # ~~~~~~~~~~~ #
    # Constructor #
    # ~~~~~~~~~~~ #

    def __init__(
            self, data: 'list' = None, shape: int = None) -> None:

        """
            Constructor for the Vector class

            Args:
                data: A list of values of the same type

            Raises:
                TypeError: If data is not a list
                ValueError: If data is empty
                TypeError: If all elements are not of the same type
        """

        if data is not None and shape is not None:
            raise ValueError("Cannot specify both data and shape")

        if shape is not None:
            self.__init_by_shape__(shape)

        else:
            self.__init_by_data__(data)

    def __init_by_shape__(self, shape: int = None):

        """
            Init util function,

            Check the shape of the Vector and initialize a new instance
        """

        if shape is None:
            raise ValueError("Shape must be defined.")

        if not isinstance(shape, int):
            raise TypeError("Shape must be an integer")
        if shape <= 0:
            raise ValueError("Shape must be greater than 0")

        self.data = [0. for _ in range(shape)]
        self.shape = shape

    def __init_by_data__(self, data):

        """
            Init util function,

            Check the data of the Vector and initialize a new instance
        """

        if data is None:
            data = []

        if not isinstance(data, list):
            raise TypeError("Data must be a list")

        if len(data) == 0:
            raise ValueError("Data must not be empty")

        value_type = type(data[0])
        if value_type in (int, float):
            value_type = (int, float)
        if not all(isinstance(x, value_type) for x in data):
            raise TypeError("All elements must be of the same type")

        if value_type in (int, float):
            for _ in range(len(data)):
                data[_] = float(data[_])

        self.data = data
        self.shape = len(data)

    # ~~~~~~~~~~~~~~~ #
    # Utility methods #
    # ~~~~~~~~~~~~~~~ #

    # Returns the size of the vector
    def size(self):
        return self.shape

    # Prints the vector
    def __str__(self) -> str:
        return (str(self.data))

    # Reshapes the vector to a matrix
    def reshape_to_matrix(self):
        mat = matrix.Matrix([[x] for x in self.data])
        self.data = mat.data
        self.shape = mat.shape
        self.__class__ = mat.__class__
        return self

    # ~~~~~~~~~~~~~~~~~~~~~~~~~~ #
    # Add, Substract and Scale   #
    # ~~~~~~~~~~~~~~~~~~~~~~~~~~ #
    # Max Time Complexity: O(n)  #
    # Max Space Complexity: O(n) #
    # ~~~~~~~~~~~~~~~~~~~~~~~~~~ #

    # Adds two vectors
    def add(self, other):
        if not isinstance(other, Vector):
            raise TypeError("Other must be a Vector")
        if self.shape != other.shape:
            raise ValueError("Both vectors must be of the same size")

        for i in range(self.shape):
            self.data[i] += other.data[i]

        return self

    # Substracts two vectors
    def sub(self, other):
        if not isinstance(other, Vector):
            raise TypeError("Other must be a Vector")
        if self.shape != other.shape:
            raise ValueError("Both vectors must be of the same size")

        for i in range(self.shape):
            self.data[i] -= other.data[i]

        return self

    # Scales a vector
    def scl(self, scalar):
        if not isinstance(scalar, (int, float)):
            raise TypeError("Scalar must be a number")

        for i in range(self.shape):
            self.data[i] *= scalar

        return self

    # ~~~~~~~~~~~~~~~~~~~~~~~~~~ #
    # Dot Product                #
    # ~~~~~~~~~~~~~~~~~~~~~~~~~~ #
    # Max Time Complexity: O(n)  #
    # Max Space Complexity: O(n) #
    # ~~~~~~~~~~~~~~~~~~~~~~~~~~ #

    def dot(u, v):
        """
            Returns the dot product of two vectors

            Args:
                u: A vector
                v: A vector

            Raises:
                TypeError: If u is not a Vector
                TypeError: If v is not a Vector
                ValueError: If u and v are not of the same size
        """

        if not isinstance(u, Vector):
            raise TypeError("U must be a Vector")
        if not isinstance(v, Vector):
            raise TypeError("V must be a Vector")
        if u.shape != v.shape:
            raise ValueError("U and V must be of the same size")

        # fma
        return sum([x * y for x, y in zip(u.data, v.data)])

    # ~~~~~~~~~~~~~~~~~~~~~~~~~~ #
    # Norm                       #
    # ~~~~~~~~~~~~~~~~~~~~~~~~~~ #
    # Max Time Complexity: O(n)  #
    # Max Space Complexity: O(n) #
    # ~~~~~~~~~~~~~~~~~~~~~~~~~~ #

    def norm(self):
        """
            Returns the norm of a vector

            Args:
                self: A vector
        """

        # opti fma + rootsquare
        dot = Vector.dot(self, self)
        return dot ** 0.5


if __name__ == "__main__":

    test = Vector([0, 1, 2, 3])

    test.reshape_to_matrix()

    print(test)
