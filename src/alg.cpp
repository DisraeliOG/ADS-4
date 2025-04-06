// Copyright 2021 NNTU-CS
void InsertionSort(int arr[], int n) {
  for (int i = 1; i < n; ++i) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = key;
  }
}

int CountPairs1(const int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        ++count;
      }
    }
  }
  return count;
}

int CountPairs2(const int* arr, int len, int value) {
  int count = 0;
  int left = 0;
  int right = len - 1;

  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      if (arr[left] == arr[right]) {
        int n = right - left + 1;
        count += n * (n - 1) / 2;
        break;
      } else {
        int left_val = arr[left];
        int count_left = 0;
        while (left < len && arr[left] == left_val) {
          ++count_left;
          ++left;
        }
        int right_val = arr[right];
        int count_right = 0;
        while (right >= 0 && arr[right] == right_val) {
          ++count_right;
          --right;
        }
        count += count_left * count_right;
      }
    } else if (sum < value) {
      ++left;
    } else {
      --right;
    }
  }
  return count;
}

int LowerBoundIndex(const int* arr, int len, int target, int start) {
  int lo = start;
  int hi = len;
  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (arr[mid] < target) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  return (lo < len && arr[lo] == target) ? lo : -1;
}

int UpperBoundIndex(const int* arr, int len, int target, int start) {
  int lo = start;
  int hi = len;
  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (arr[mid] <= target) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  return lo;
}

int CountPairs3(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len;) {
    int a = arr[i];
    int count_a = 0;
    while (i < len && arr[i] == a) {
      ++count_a;
      ++i;
    }
    int complement = value - a;
    if (a > complement) break;

    if (a == complement) {
      count += count_a * (count_a - 1) / 2;
    } else {
      int lo = LowerBoundIndex(arr, len, complement, i);
      if (lo == -1) continue;
      int hi = UpperBoundIndex(arr, len, complement, i);
      int count_b = hi - lo;
      count += count_a * count_b;
    }
  }
  return count;
}
