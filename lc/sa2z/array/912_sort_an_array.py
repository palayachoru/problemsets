def bubble_sort(nums: List[int]):
  for i in range(len(nums)):
    has_swapped = False

    for j in range(1, len(nums) - i):
      if nums[j - 1] > nums[j]:
        nums[j - 1], nums[j] = nums[j], nums[j - 1]
        has_swapped = True

    # if swap not happened, then the array is sorted
    if not has_swapped:
      break


def selection_sort(nums: List[int]):
  for i in range(len(nums)):
    min_idx = i

    for j in range(i + 1, len(nums)):
      if (nums[j] < nums[min_idx]):
        min_idx = j

    nums[i], nums[min_idx] = nums[min_idx], nums[i]


def insertion_sort(nums: List(int)):
  for k in range(1, len(nums)):
    key = nums[k]
    key_prev_idx = k - 1

    while (key_prev_idx >= 0 and key < nums[key_prev_idx]):
      nums[key_prev_idx + 1] = nums[key_prev_idx]
      key_prev_idx -= 1

    nums[key_prev_idx + 1] = key







class Solution:
  def sortArray(self, nums: List[int]) -> List[int]:
    insertion_sort(nums)
    return nums
        
