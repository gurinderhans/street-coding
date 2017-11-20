while 1:
  try:
    inp = input()
    print("len:",len(inp))
    num=int(inp)
    if num==0:
      break

    isnot=" "
    if num % 11 != 0:
      isnot = " not "

    out_str = "{} is{}a multiple of 11.".format(num, isnot);
    print(out_str)
  except:
    break
