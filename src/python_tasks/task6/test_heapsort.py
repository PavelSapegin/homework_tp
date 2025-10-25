from heapsort import heap_sort
from sortings import quick_sort, bubble_sort, insert_sort
import pytest
import random

@pytest.mark.parametrize(
    ["arr","expected"],(([1,5,7,1,21],[1,1,5,7,21]),([8,5,4,90,21],[4,5,8,21,90]),([4,5,8,12],[4,5,8,12]))
)
def test_heap_sort(arr,expected):

    assert heap_sort(arr) == expected


@pytest.mark.parametrize(
    ["arr","expected"],[([-10,12341,-10000,-100],[-10000,-100,-10,12341]),([42],[42]),([9,9,9,9],[9,9,9,9]),([10,20,30,40,50,60],[10,20,30,40,50,60])]
)
def test_egde_cases_heap_sort(arr,expected):
    assert heap_sort(arr) == expected


def generate_list():
    n = random.randint(0,100)
    arr = [random.randint(-10000,10000) for _ in range(n)]
    return arr

def test_property_based_heap_sort():
    for _ in range(10000):
        arr = generate_list()
        assert heap_sort(arr) == bubble_sort(arr)
        assert heap_sort(arr) == quick_sort(arr)
        assert heap_sort(arr) == insert_sort(arr)
