// Copyright 2021 NNTU-CS
int countPairs1(const int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        ++count;
      }
    }
  }
  return count;
}

int countPairs2(const int* arr, int len, int value) {
  int count = 0;
  int left = 0;
  int right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      ++count;
      ++left;
      --right;
    } else if (sum < value) {
      ++left;
    } else {
      --right;
    }
  }
  return count;
}

bool binarySearch(const int* arr, int left, int right, int target) {
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
      return true;
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return false;
}

int countPairs3(const int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; ++i) {
    int target = value - arr[i];
    if (binarySearch(arr, i + 1, len - 1, target)) {
      ++count;
    }
  }
  return count;
}

