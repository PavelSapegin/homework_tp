import pytest
import random
from heapsort import heap_sort
from sortings import quick_sort, bubble_sort, insert_sort


@pytest.mark.parametrize(
    ["arr", "expected"],
    (
        ([1, 5, 7, 1, 21], [1, 1, 5, 7, 21]),
        ([8, 5, 4, 90, 21], [4, 5, 8, 21, 90]),
        ([4, 5, 8, 12], [4, 5, 8, 12]),
    ),
)
def test_heap_sort(arr, expected):

    assert heap_sort(arr) == expected


@pytest.mark.parametrize(
    ["arr", "expected"],
    [
        ([-10, 12341, -10000, -100], [-10000, -100, -10, 12341]),
        ([42], [42]),
        ([9, 9, 9, 9], [9, 9, 9, 9]),
        ([10, 20, 30, 40, 50, 60], [10, 20, 30, 40, 50, 60]),
    ],
)
def test_egde_cases_heap_sort(arr, expected):
    assert heap_sort(arr) == expected


@pytest.fixture
def generated_list():
    n = random.randint(0, 100)
    arr = [random.randint(-10000, 10000) for _ in range(n)]
    return arr


def test_property_based_heap_sort(generated_list):
    for _ in range(10000):
        heap = heap_sort(generated_list)
        bubble = bubble_sort(generated_list)
        quick = quick_sort(generated_list)
        insert = insert_sort(generated_list)

        assert len(heap) == len(bubble)
        assert len(heap) == len(quick)
        assert len(heap) == len(insert)

        assert heap == bubble
        assert heap == quick
        assert heap == insert
