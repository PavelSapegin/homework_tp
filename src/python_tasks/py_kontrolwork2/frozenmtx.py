from oper_matrix import Matrix


class FrozenMatrix(Matrix):
    def __init__(self, data):
        super().__init__(data)

        self.data = tuple(tuple(row) for row in data)

        self.hash = None

    def __hash__(self):
        if self.hash is None:
            self.hash = hash(self.data)

        return self.hash


a = FrozenMatrix(data=[[12, 12], [12, 12]])

a[0][1] = 1
