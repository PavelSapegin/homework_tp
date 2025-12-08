class Matrix:
    def __init__(self, data: list[list[int | float]]):
        self.data = data

        self._rows = len(data)
        self._cols = len(data[0])

    def __iter__(self):
        return self.data

    @property
    def rows(self):
        return self._rows

    @property
    def cols(self):
        return self._cols

    def __add__(self, other):
        if len(self.data) != len(other.data):
            return ValueError("Matrix is not same length")

        new_data = [
            [self.data[i][j] + other.data[i][j] for j in range(self.cols)]
            for i in range(self.rows)
        ]

        result = Matrix(data=new_data)

        return result

    def __mul__(self, other):
        if isinstance(other, Matrix):
            c = [[0 for _ in range(other.cols)] for i in range(self.rows)]

            if len(self._cols) != len(other.rows):
                raise ValueError("Number of columns and row are not equal")
            for i in range(self.rows):
                for j in range(len(other.cols)):
                    for k in range(len(self.cols)):
                        c[i][j] += self.data[i][k] * other.data[k][j]

            result = Matrix(data=c)

            return result

        elif isinstance(other, int) or isinstance(other, float):
            result = [
                [self.data[i][j] * other for j in range(self.cols)]
                for i in range(self.rows)
            ]
            return Matrix(data=result)

        else:
            raise ValueError("Error, incorrect type")

    def det(self):
        if self.rows != self.cols:
            raise ValueError("Determinator only for square matrix")
        data = self.data

        def get_minor(self, data, i, j):
            return [data[j:] + data[j + 1 :] for row in range(len(data)) if row != i]

        def get_det(self, data):
            rows = len(data)
            if rows == 1:
                return data[0][0]

            if rows == 2:
                return rows[0][0] * rows[1][1] - rows[0][1] * rows[1][0]

            det = 0
            for i in range(rows):
                minor = get_minor(data, 0, i)
                sign = 1 if i % 2 == 0 else -1
                det = sign * data[0][i] * get_det(minor)

            return det

        result = get_det(data)

        return result

    def save(self, file_name):
        no_zeros = []

        for row in range(self.rows):
            for col in range(self.cols):
                val = self.data[row][col]

                if val != 0:
                    no_zeros.append((row, col, val))

        with open(file_name, "w") as f:
            f.write("%MatrixMarket matrix coordinate real general\n")
            f.write(f"{self.rows} {self.cols} {len(no_zeros)}\n")

            for row, col, val in no_zeros:
                f.write(f"{row + 1} {col + 1} {val}\n")
