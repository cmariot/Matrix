import unittest

try:
    from ..matrix.matrix import Matrix
except ImportError as e:
    print("Error:", e)

try:
    from ..matrix.vector import Vector
except ImportError as e:
    print("Error:", e)


class TestMatrix(unittest.TestCase):

    # ~~~~~~~~~~~~~~~~~~ #
    # Matrix Constructor #
    # ~~~~~~~~~~~~~~~~~~ #

    def test_init_with_data(self):

        # Test initialization with data
        data = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
        matrix = Matrix(data=data)
        self.assertEqual(matrix.data, data)
        self.assertEqual(matrix.shape, (3, 3))

        # Test initialization with data of different types
        data = [[1, 2, 3], [4.0, 5.0, 6.0], [7, 8, 9]]
        matrix = Matrix(data=data)
        self.assertEqual(matrix.data, [[1.0, 2.0, 3.0],
                                       [4.0, 5.0, 6.0],
                                       [7.0, 8.0, 9.0]])
        self.assertEqual(matrix.shape, (3, 3))

        # Test initialization with empty data
        with self.assertRaises(ValueError):
            matrix = Matrix(data=[])

        # Test initialization with non-list data
        with self.assertRaises(TypeError):
            matrix = Matrix(data=1)

        # Test initialization with non-list elements in data
        with self.assertRaises(TypeError):
            matrix = Matrix(data=[1, 2, 3])

        # Test initialization with lists of different lengths
        with self.assertRaises(ValueError):
            matrix = Matrix(data=[[1, 2, 3], [4, 5], [7, 8, 9]])

        # Test initialization with elements of different types
        with self.assertRaises(TypeError):
            matrix = Matrix(data=[[1, 2, 3], [4, 5, 6], [7, 8, '9']])

    def test_init_with_shape(self):
        # Test initialization with shape
        shape = (3, 3)
        matrix = Matrix(shape=shape)
        self.assertEqual(matrix.data, [[0, 0, 0], [0, 0, 0], [0, 0, 0]])
        self.assertEqual(matrix.shape, shape)

        shape = (3, 2)
        matrix = Matrix(shape=shape)
        self.assertEqual(matrix.data, [[0, 0], [0, 0], [0, 0]])
        self.assertEqual(matrix.shape, shape)

        # Test initialization with empty shape
        with self.assertRaises(ValueError):
            matrix = Matrix(shape=())

        # Test initialization with non-tuple shape
        with self.assertRaises(TypeError):
            matrix = Matrix(shape=[])

        # Test initialization with shape of length other than 2
        with self.assertRaises(ValueError):
            matrix = Matrix(shape=(3, 3, 3))

        # Test initialization with non-integer elements in shape
        with self.assertRaises(TypeError):
            matrix = Matrix(shape=('3', '3'))

        # Test initialization with non-positive elements in shape
        with self.assertRaises(ValueError):
            matrix = Matrix(shape=(-3, 3))

    def test_init_with_both_data_and_shape(self):
        # Test initialization with both data and shape
        with self.assertRaises(ValueError):
            Matrix(data=[[1, 2, 3]], shape=(3, 3))

    def test_init_with_none_data_and_shape(self):
        # Test initialization with none data and shape
        with self.assertRaises(ValueError):
            Matrix(data=None, shape=None)

    def test_init_with_float_data(self):
        # Test initialization with float data
        data = [[1.0, 2.0, 3.0], [4.0, 5.0, 6.0], [7.0, 8.0, 9.0]]
        matrix = Matrix(data=data)
        self.assertEqual(matrix.data, data)
        self.assertEqual(matrix.shape, (3, 3))

    def test_init_with_int_data(self):
        # Test initialization with int data
        data = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
        matrix = Matrix(data=data)
        self.assertEqual(matrix.data, [[1.0, 2.0, 3.0],
                                       [4.0, 5.0, 6.0],
                                       [7.0, 8.0, 9.0]])
        self.assertEqual(matrix.shape, (3, 3))

    def test_init_with_bool_data(self):
        # Test initialization with bool data
        data = [[True, False], [False, True]]
        matrix = Matrix(data=data)
        self.assertEqual(matrix.data, [[1.0, 0.0], [0.0, 1.0]])
        self.assertEqual(matrix.shape, (2, 2))

    # ~~~~~~~~~~~~~~~~~~~~~~ #
    # Matrix Utility methods #
    # ~~~~~~~~~~~~~~~~~~~~~~ #

    def test_size(self):
        # Test size method
        m = Matrix([[1, 2], [3, 4]])
        self.assertEqual(m.size(), (2, 2))

    def test_isSquare(self):
        # Test isSquare method with square matrix
        m = Matrix([[1, 2], [3, 4]])
        self.assertTrue(m.isSquare())

        # Test isSquare method with non-square matrix
        m = Matrix([[1, 2, 3], [4, 5, 6]])
        self.assertFalse(m.isSquare())

    def test_reshape_to_vector(self):
        # Test reshape_to_vector method
        m = Matrix([[1, 2], [3, 4]])
        v = m.reshape_to_vector()
        self.assertIsInstance(v, Vector)
        self.assertEqual(v.data, [1, 2, 3, 4])
        self.assertEqual(v.shape, 4)

    # ~~~~~~~~~~~~~~~~~~~~~~~ #
    # Matrix Arithmetic tests #
    # ~~~~~~~~~~~~~~~~~~~~~~~ #

    def test_add_with_valid_input(self):
        # Test add method with valid input
        m1 = Matrix([[1, 2], [3, 4]])
        m2 = Matrix([[5, 6], [7, 8]])
        m1.add(m2)
        self.assertEqual(m1.data, [[6, 8], [10, 12]])

    def test_add_with_invalid_input(self):
        # Test add method with invalid input (not a matrix)
        m = Matrix([[1, 2], [3, 4]])
        v = [1, 2, 3]
        with self.assertRaises(TypeError) as context:
            m.add(v)
        self.assertEqual(str(context.exception), "Other must be a Matrix")

        # Test add method with invalid input (matrices have different shapes)
        m1 = Matrix([[1, 2], [3, 4]])
        m2 = Matrix([[5, 6]])
        with self.assertRaises(ValueError) as context:
            m1.add(m2)
        self.assertEqual(str(context.exception),
                         "Both matrices must be of the same size")

    def test_sub_with_valid_input(self):
        # Test sub method with valid input
        m1 = Matrix([[1, 2], [3, 4]])
        m2 = Matrix([[5, 6], [7, 8]])
        m1.sub(m2)
        self.assertEqual(m1.data, [[-4, -4], [-4, -4]])

    def test_sub_with_invalid_input(self):
        # Test sub method with invalid input (not a matrix)
        m = Matrix([[1, 2], [3, 4]])
        v = [1, 2, 3]
        with self.assertRaises(TypeError) as context:
            m.sub(v)
        self.assertEqual(str(context.exception), "Other must be a Matrix")

        # Test sub method with invalid input (matrices have different shapes)
        m1 = Matrix([[1, 2], [3, 4]])
        m2 = Matrix([[5, 6]])
        with self.assertRaises(ValueError) as context:
            m1.sub(m2)
        self.assertEqual(str(context.exception),
                         "Both matrices must be of the same size")

    def test_scl_with_valid_input(self):
        # Test scl method with valid input
        m = Matrix([[1, 2], [3, 4]])
        m.scl(2)
        self.assertEqual(m.data, [[2, 4], [6, 8]])

    def test_scl_with_invalid_input(self):
        # Test scl method with invalid input (not a number)
        m = Matrix([[1, 2], [3, 4]])
        s = 'a'
        with self.assertRaises(TypeError) as context:
            m.scl(s)
        self.assertEqual(str(context.exception), "Scalar must be a number")


class TestVector(unittest.TestCase):

    # ~~~~~~~~~~~~~~~~~~~~~~~ #
    # Vector Constructor test #
    # ~~~~~~~~~~~~~~~~~~~~~~~ #

    def test_constructor_with_valid_input(self):
        # Test with valid input
        v = Vector([1, 2, 3])
        self.assertEqual(v.data, [1, 2, 3])
        self.assertEqual(v.shape, 3)

    def test_constructor_with_empty_list(self):
        # Test with empty list
        with self.assertRaises(ValueError) as context:
            Vector([])
        self.assertEqual(str(context.exception), "Data must not be empty")

    def test_constructor_with_invalid_input(self):
        # Test with invalid input (not a list)
        with self.assertRaises(TypeError) as context:
            Vector(123)
        self.assertEqual(str(context.exception), "Data must be a list")

        # Test with invalid input (not all elements are of the same type)
        with self.assertRaises(TypeError) as context:
            Vector([1, 2, 'a'])
        self.assertEqual(str(context.exception),
                         "All elements must be of the same type")

    # ~~~~~~~~~~~~~~~~~~~~~~ #
    # Vector Utility methods #
    # ~~~~~~~~~~~~~~~~~~~~~~ #

    def test_size(self):
        # Test size method
        v = Vector([1, 2, 3])
        self.assertEqual(v.size(), 3)

    def test_reshape_to_matrix(self):
        # Test reshape_to_matrix method
        v = Vector([1, 2, 3])
        m = v.reshape_to_matrix()
        self.assertIsInstance(m, Matrix)
        self.assertEqual(m.data, [[1], [2], [3]])

    # ~~~~~~~~~~~~~~~~~~~~~~~ #
    # Vector Arithmetic tests #
    # ~~~~~~~~~~~~~~~~~~~~~~~ #

    def test_add_with_valid_input(self):
        # Test add method with valid input
        m1 = Matrix([[1, 2], [3, 4]])
        m2 = Matrix([[5, 6], [7, 8]])
        m1.add(m2)
        self.assertEqual(m1.data, [[6, 8], [10, 12]])

    def test_add_with_invalid_input(self):
        # Test add method with invalid input (not a vector)
        m = Matrix([[1, 2], [3, 4]])
        v = [1, 2, 3]
        with self.assertRaises(TypeError) as context:
            m.add(v)
        self.assertEqual(str(context.exception), "Other must be a Matrix")

        # Test add method with invalid input (vectors have different shapes)
        v1 = Vector([1, 2, 3])
        v2 = Vector([4, 5])
        with self.assertRaises(ValueError) as context:
            v1.add(v2)
        self.assertEqual(str(context.exception),
                         "Both vectors must be of the same size")

    def test_sub_with_valid_input(self):
        # Test sub method with valid input
        m1 = Matrix([[1, 2], [3, 4]])
        m2 = Matrix([[5, 6], [7, 8]])
        m1.sub(m2)
        self.assertEqual(m1.data, [[-4, -4], [-4, -4]])

    def test_sub_with_invalid_input(self):
        # Test sub method with invalid input (not a vector)
        m = Matrix([[1, 2], [3, 4]])
        v = [1, 2, 3]
        with self.assertRaises(TypeError) as context:
            m.sub(v)
        self.assertEqual(str(context.exception), "Other must be a Matrix")

        # Test sub method with invalid input (vectors have different shapes)
        v1 = Vector([1, 2, 3])
        v2 = Vector([4, 5])
        with self.assertRaises(ValueError) as context:
            v1.sub(v2)
        self.assertEqual(str(context.exception),
                         "Both vectors must be of the same size")

    def test_scl_with_valid_input(self):
        # Test scl method with valid input
        m = Matrix([[1, 2], [3, 4]])
        m.scl(2)
        self.assertEqual(m.data, [[2, 4], [6, 8]])

    def test_scl_with_invalid_input(self):
        # Test scl method with invalid input (not a number)
        m = Matrix([[1, 2], [3, 4]])
        s = 'a'
        with self.assertRaises(TypeError) as context:
            m.scl(s)
        self.assertEqual(str(context.exception), "Scalar must be a number")


if __name__ == '__main__':
    unittest.main()
