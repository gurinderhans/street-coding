def phone_combos(num): # num would be, for instance, '327'
  key_pad = {'2' : ['a','b','c'],
  '3' : ['d','e','f'],
  '4' : ['g','h','i'],
  '5' : ['j','k', 'l'],
  '6' : ['m', 'n', 'o'],
  '7' : ['p', 'q', 'r','s'],
  '8' : ['t', 'u', 'v'],
  '9' : ['w', 'x', 'y', 'z']}
  
  result = [[]]
  arg = [key_pad[num[i]] for i in range(len(num))]
  for pool in arg:
    print pool
    result = [x+[y] for x in result for y in pool]
    for y in pool:
      for x in result:
        print y,x
    print result

  return result

for i in phone_combos('234'):
  # print i
  pass
