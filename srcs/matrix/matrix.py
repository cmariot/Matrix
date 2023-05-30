import vector


class Matrix:

    # ~~~~~~~~~~~ #
    # Constructor #
    # ~~~~~~~~~~~ #

    def __init__(
            self,
            data: list = None,
            shape: 'tuple[int]' = None
    ) -> None:
        """
            Constructor for the Matrix class

            Args:
                data: A list of lists of values of the same type
                or
                shape: A tuple of the form (rows, columns)

            Raises:
                ValueError: If data and shape are both None
                TypeError: If shape is not a tuple
                ValueError: If shape is not of length 2
                TypeError: If shape contains non-integers
                ValueError: If shape contains non-positive integers
                TypeError: If data is not a list
                ValueError: If data is empty
                TypeError: If all elements are not lists
                ValueError: If all lists are not of the same length
                TypeError: If all elements are not of the same type
        """

        if data is None and shape is None:
            raise ValueError("Data and shape cannot both be None")

        elif data is not None and shape is not None:
            raise ValueError("Data and shape cannot both be not None")

        if shape is not None:
            self.__init_by_shape__(shape)

        elif data is not None:
            self.__init_by_data__(data)

    def __init_by_shape__(self, shape: 'tuple[int]' = None):
        if not isinstance(shape, tuple):
            raise TypeError("Shape must be a tuple")
        elif len(shape) != 2:
            raise ValueError("Shape must be of length 2")
        elif not all(isinstance(x, int) for x in shape):
            raise TypeError("Shape must only contain integers")
        elif not all(x > 0 for x in shape):
            raise ValueError("Shape must only contain positive integers")

        self.data = [[0.
                      for _ in range(shape[1])]
                     for _ in range(shape[0])]
        self.shape = shape

    def __init_by_data__(self, data: list = None):

        if not isinstance(data, list):
            raise TypeError("Data must be a list")
        elif len(data) == 0:
            raise ValueError("Data must not be empty")

        if not all(isinstance(x, list) for x in data):
            raise TypeError("All elements must be lists")

        value_length = len(data[0])
        if value_length == 0:
            raise ValueError("All lists must not be empty")
        elif not all(len(x) == value_length for x in data):
            raise ValueError("All lists must be of the same length")

        value_type = type(data[0][0])
        if value_type in (int, float):
            value_type = (int, float)

        for x in data:
            if not all(isinstance(y, value_type) for y in x):
                raise TypeError("All elements must be of the same type")

        # Convert all values to float
        if value_type in (int, float):
            for i in range(len(data)):
                for j in range(len(data[0])):
                    data[i][j] = float(data[i][j])

        self.data = data
        self.shape = (len(data), len(data[0]))

    # ~~~~~~~~~~~~~~~ #
    # Utility methods #
    # ~~~~~~~~~~~~~~~ #

    # Returns the size of the matrix
    def size(self):
        return self.shape

    # Returns true if the matrix is square
    def isSquare(self):
        return self.shape[0] == self.shape[1]

    # Prints the matrix
    def __str__(self) -> str:
        return "\n".join([", ".join([str(y) for y in x]) for x in self.data])

    # Reshapes the matrix to a vector
    def reshape_to_vector(self):
        vec = vector.Vector([x for y in self.data for x in y])
        self.shape = vec.shape
        self.data = vec.data
        self.__class__ = vec.__class__
        self = vec
        return self

    # ~~~~~~~~~~~~~~~~~~~~~~~~~~ #
    # Add, Substract and Scale   #
    # ~~~~~~~~~~~~~~~~~~~~~~~~~~ #
    # Max Time Complexity: O(n)  #
    # Max Space Complexity: O(n) #
    # ~~~~~~~~~~~~~~~~~~~~~~~~~~ #

    # Adds two matrices
    def add(self, other):
        if not isinstance(other, Matrix):
            raise TypeError("Other must be a Matrix")
        if self.shape != other.shape:
            raise ValueError("Both matrices must be of the same size")

        for i in range(self.shape[0]):
            for j in range(self.shape[1]):
                self.data[i][j] += other.data[i][j]

        return self

    # Substracts two matrices
    def sub(self, other):
        if not isinstance(other, Matrix):
            raise TypeError("Other must be a Matrix")
        if self.shape != other.shape:
            raise ValueError("Both matrices must be of the same size")

        for i in range(self.shape[0]):
            for j in range(self.shape[1]):
                self.data[i][j] -= other.data[i][j]

        return self

    # Scales a matrix
    def scl(self, scalar):
        if not isinstance(scalar, (int, float)):
            raise TypeError("Scalar must be a number")

        for i in range(self.shape[0]):
            for j in range(self.shape[1]):
                self.data[i][j] *= scalar

        return self


if __name__ == "__main__":

    test = Matrix([[0, 1, 2],
                   [3, 4, 5],
                   [6, 7, 8]])

    test.reshape_to_vector()

    print(test)
