def wrapper(nums1, nums2):
  X,Y=[],[]
  if len(nums1) < len(nums2):
    X,Y=nums1,nums2
  else:
    X,Y=nums2,nums1
  
  return median(X, Y, 0, len(X))

def median(X, Y, start, end):
  H = (len(X) + len(Y) + 1) // 2

  xp = (start + end) // 2
  yp = H-xp

  ninf=lambda: [float("-inf")]
  inf=lambda: [float("inf")]

  LX,RX = X[:xp] or ninf(), X[xp:] or inf()
  LY,RY = Y[:yp] or ninf(), Y[yp:] or inf()

  if LX[-1] <= RY[0] and LY[-1] <= RX[0]:
    if (len(X)+len(Y))%2 != 0:
      return max(LX[-1], LY[-1])
    else:
      mxL = max(LX[-1], LY[-1])
      mnR = min(RY[0], RX[0])
      return (mxL+mnR)/2.0
  elif LY[-1] > RX[0]: # move right and rebalance
    return median(X, Y, xp+1, end)
  else: # move left and rebalance
    return median(X, Y, start, xp-1)

res = wrapper([1,2], [3])
# wrapper([23,26,31,35], [3,5,7,9,11,16])
# wrapper([1,3,8,9,15], [7,11,18,19,21,25])
print(res)
