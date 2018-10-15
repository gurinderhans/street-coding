

def timeConversion(s):
  # Complete this function
  sections = s.split(":")
  hour=int(sections[0])
  if "PM" in sections[-1] and hour < 12:
    hour += 12

  if "AM" in sections[-1] and hour == 12:
    hour -= 12

  seconds = sections[2][:-2]
  return str(hour).zfill(2) + ":"+ sections[1] +":" + seconds

s="07:05:45PM"
s="12:00:00AM"
print timeConversion(s)
