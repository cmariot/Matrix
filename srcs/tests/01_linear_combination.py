import unittest
from ..matrix.vector import Vector
from ..matrix import linear_combination as linear_combination


class TestVector(unittest.TestCase):

    def test_linear_combination_with_valid_input(self):
        # Test linear_combination function with valid input
        v1 = Vector([1, 2, 3])
        v2 = Vector([4, 5, 6])
        vectors = [v1, v2]
        coeffs = [2, 3]
        result = linear_combination(vectors, coeffs)
        self.assertEqual(result.data, [14, 19, 24])

        # Subject example 1
        e1 = Vector([1., 0., 0.])
        e2 = Vector([0., 1., 0.])
        e3 = Vector([0., 0., 1.])
        v1 = Vector([1., 2., 3.])
        v2 = Vector([0., 10., -100.])
        vectors = [e1, e2, e3]
        coeffs = [10., -2., 0.5]
        result = linear_combination(vectors, coeffs)
        self.assertEqual(result.data, [10., -2., 0.5])

        # Subject example 2
        vectors = [v1, v2]
        coeffs = [10., -2.]
        result = linear_combination(vectors, coeffs)
        self.assertEqual(result.data, [10., 0., 230.])

    def test_linear_combination_with_invalid_input(self):
        # Test linear_combination function with invalid input
        # (vectors not a list)
        v = Vector([1, 2, 3])
        coeffs = [2, 3]
        with self.assertRaises(TypeError) as context:
            linear_combination(v, coeffs)
        self.assertEqual(str(context.exception), "Vectors must be a list")

        # Test linear_combination function with invalid input
        # (coeffs not a list)
        v1 = Vector([1, 2, 3])
        v2 = Vector([4, 5, 6])
        vectors = [v1, v2]
        c = 2
        with self.assertRaises(TypeError) as context:
            linear_combination(vectors, c)
        self.assertEqual(str(context.exception), "Coeffs must be a list")

        # Test linear_combination function with invalid input (vectors empty)
        vectors = []
        coeffs = [2, 3]
        with self.assertRaises(ValueError) as context:
            linear_combination(vectors, coeffs)
        self.assertEqual(str(context.exception), "Vectors must not be empty")

        # Test linear_combination function with invalid input (coeffs empty)
        v1 = Vector([1, 2, 3])
        v2 = Vector([4, 5, 6])
        vectors = [v1, v2]
        coeffs = []
        with self.assertRaises(ValueError) as context:
            linear_combination(vectors, coeffs)
        self.assertEqual(str(context.exception), "Coeffs must not be empty")

        # Test linear_combination function with invalid input
        # (vectors and coeffs different sizes)
        v1 = Vector([1, 2, 3])
        v2 = Vector([4, 5, 6])
        vectors = [v1, v2]
        coeffs = [2]
        with self.assertRaises(ValueError) as context:
            linear_combination(vectors, coeffs)
        self.assertEqual(str(context.exception),
                         "Vectors and Coeffs must be of the same size")

        # Test linear_combination function with invalid input
        # (vectors not all Vector objects)
        v1 = Vector([1, 2, 3])
        v2 = [4, 5, 6]
        vectors = [v1, v2]
        coeffs = [2, 3]
        with self.assertRaises(TypeError) as context:
            linear_combination(vectors, coeffs)
        self.assertEqual(str(context.exception),
                         "All elements of vectors must be a Vector")

        # Test linear_combination function with invalid input
        # (coeffs not all numbers)
        v1 = Vector([1, 2, 3])
        v2 = Vector([4, 5, 6])
        vectors = [v1, v2]
        coeffs = [2, 'a']
        with self.assertRaises(TypeError) as context:
            linear_combination(vectors, coeffs)
        self.assertEqual(str(context.exception),
                         "All elements of coeffs must be a number")


if __name__ == '__main__':
    unittest.main()
