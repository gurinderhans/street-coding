

def arr_sum_recurse(arr):
  if len(arr)==1:
    return arr[0]
  return arr[0]+arr_sum_recurse(arr[1:])

def arr_sum_tail_recurse(arr, i, sm):
	if len(arr)==i:
		return sm
	return arr_sum_tail_recurse(arr, i+1, sm+arr[i])


arr=[1,2,3,5,3,1,2,31,21,1,31,3,13,1,13,31,31,14,41,14,1,123,25,43,34,53,34,534,534,52]
# arr=[1,2,3]

print sum(arr)
print arr_sum_recurse(arr)
print arr_sum_tail_recurse(arr,0,0)
