import unittest
from Matrix import Matrix
from Matrix import Vector


class TestMatrix(unittest.TestCase):

    # ~~~~~~~~~~~~~~~~~~ #
    # Matrix Constructor #
    # ~~~~~~~~~~~~~~~~~~ #

    def test_constructor_with_valid_input(self):
        # Test with valid input
        m = Matrix([[1, 2], [3, 4]])
        self.assertEqual(m.data, [[1, 2], [3, 4]])
        self.assertEqual(m.shape, (2, 2))

    def test_constructor_with_empty_list(self):
        # Test with empty list
        with self.assertRaises(ValueError) as context:
            Matrix([])
        self.assertEqual(str(context.exception), "Data must not be empty")

    def test_constructor_with_invalid_input(self):
        # Test with invalid input (not a list)
        with self.assertRaises(TypeError) as context:
            Matrix(123)
        self.assertEqual(str(context.exception), "Data must be a list")

        # Test with invalid input (not all elements are lists)
        with self.assertRaises(TypeError) as context:
            Matrix([[1, 2], 3])
        self.assertEqual(str(context.exception), "All elements must be lists")

        # Test with invalid input (not all lists are of the same length)
        with self.assertRaises(ValueError) as context:
            Matrix([[1, 2], [3]])
        self.assertEqual(str(context.exception),
                         "All lists must be of the same length")

        # Test with invalid input (not all elements are of the same type)
        with self.assertRaises(TypeError) as context:
            Matrix([[1, 2], [3, 'a']])
        self.assertEqual(str(context.exception),
                         "All elements must be of the same type")

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
