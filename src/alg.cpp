// Copyright 2021 NNTU-CS
void insertionSort(int arr[], int n) {
  for (int i = 1; i < n; ++i) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) count++;
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int left = 0, right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      if (arr[left] == arr[right]) {
        int n = right - left + 1;
        count += n * (n - 1) / 2;
        break;
      } else {
        int leftVal = arr[left], countLeft = 0;
        while (left < len && arr[left] == leftVal) {
          countLeft++;
          left++;
        }
        int rightVal = arr[right], countRight = 0;
        while (right >= 0 && arr[right] == rightVal) {
          countRight++;
          right--;
        }
        count += countLeft * countRight;
      }
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count;
}

int lower_bound_index(int *arr, int len, int target, int start) {
  int lo = start, hi = len;
  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (arr[mid] < target)
      lo = mid + 1;
    else
      hi = mid;
  }
  return (lo < len && arr[lo] == target) ? lo : -1;
}

int upper_bound_index(int *arr, int len, int target, int start) {
  int lo = start, hi = len;
  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (arr[mid] <= target)
      lo = mid + 1;
    else
      hi = mid;
  }
  return lo;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;

  for (int i = 0; i < len;) {
    int a = arr[i];
    int countA = 0;
    while (i < len && arr[i] == a) {
      countA++;
      i++;
    }
    int complement = value - a;

    if (a > complement) break;
    if (a == complement) {
      count += countA * (countA - 1) / 2;
    } else {
      int lo = lower_bound_index(arr, len, complement, i);
      if (lo == -1) continue;
      int hi = upper_bound_index(arr, len, complement, i);
      int countB = hi - lo;
      count += countA * countB;
    }
  }
  return count;
}

