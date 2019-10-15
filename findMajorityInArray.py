def group(arr, low, high):
  if(low < high):
    pi = partition(arr, low, high)

    group(arr, low, pi-1)
    group(arr, pi+1, high)


def partition(arr, low, high):
  pivot = arr[high]

  i = (low-1)
  
  for j in range(low, high):
    if(arr[j] == pivot): 
      i += 1
      temp = arr[i]
      arr[i] = arr[j]
      arr[j] = temp

  temp1 = arr[i+1]
  arr[i+1] = arr[high]
  arr[high] = temp1

  return i+1

def printArr(arr):
  for item in arr:
    print(item)


def findMajority(arr):
  group(arr, 0, len(arr)-1)
  print(arr)
  val = -1
  streak = 0
  for item in arr:
    if(item != val):
      streak = 1
      val = item
    else:
      streak += 1

    if streak > len(arr)//2:
      return val
  
  return -1

arr = [1,2,3,4,1,2,1,1,5,1,1]
print(findMajority(arr))

arr = [2,2,3,4,1,10,2,1,2,5,1,1,2,2,2,2,2,2,2]
print(findMajority(arr))