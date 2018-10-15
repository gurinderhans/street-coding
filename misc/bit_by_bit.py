while 1:
  n=input()
  if n==0: break;

  mask=['?']*32;
  
  for i in range(n):
    cmd=raw_input().split();
    code=cmd[0]; i=int(cmd[1]);

    if code == "SET":
      mask[i]=1;
    elif code == "CLEAR":
      mask[i]=0;
    elif code == "AND":
      j=int(cmd[2]);
      if mask[i]==1 and mask[j]==1:
        mask[i]=1;
      elif mask[i]==0 or mask[j]==0:
        mask[i]=0;
      else:
        mask[i]='?';
    elif code == "OR":
      j=int(cmd[2]);
      if mask[i]==1 or mask[j]==1:
        mask[i]=1;
      elif mask[i]==0 and mask[j]==0:
        mask[i]=0;
      else:
        mask[i]='?';
  print ''.join(map(str,mask[::-1]))

