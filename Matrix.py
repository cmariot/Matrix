from decimal import Decimal


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

        elif data is not None:

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
            if value_type == int:
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
        return Vector([x for y in self.data for x in y])

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

            if not isinstance(shape, int):
                raise TypeError("Shape must be an integer")
            if shape <= 0:
                raise ValueError("Shape must be greater than 0")

            self.data = [0. for _ in range(shape)]
            self.shape = shape

        else:

            if data is None:
                data = []

            if not isinstance(data, list):
                raise TypeError("Data must be a list")

            if len(data) == 0:
                raise ValueError("Data must not be empty")

            value_type = type(data[0])
            if not all(isinstance(x, value_type) for x in data):
                raise TypeError("All elements must be of the same type")

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
        return ", ".join(self.data)

    # Reshapes the vector to a matrix
    def reshape_to_matrix(self):
        return Matrix([[x] for x in self.data])

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

        dot = Vector.dot(self, self)
        return dot ** 0.5
