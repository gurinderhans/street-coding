

class TicTacToe(object):
  def __init__(self):
    self.board = [['-' for j in xrange(3)] for i in xrange(3)]

  def add_token(self, token_str, pos=(0,0)):
    row,col=pos
    self.board[row][col]=token_str

  def is_full(self):
    for row in self.board:
      for col in row:
        if col == '-':
          return False
    
    return True

  def ai(self):
    if board.is_full():
      raise Exception('Unable to make a move, board is full.')

    for row in xrange(len(self.board)):
      for col in xrange(len(self.board[0])):
        if self.board[row][col]=='-':
          self.board[row][col]='o'
          return

  def human(self, inp):
    inp=inp.split(" ")
    if len(inp) != 2:
      raise Exception('Invalid Input')

    inp=map(int, inp)

    row,col=inp
    if (row > len(self.board) or row < 0) and (col > len(self.board[0]) or col < 0):
      raise Exception('user input is out of bounds')

    if self.board[row][col] == '-':
      self.board[row][col]='x'
    else:
      raise Exception("Already made a move at this location")

  def print_(self):
    for row in self.board:
      print '|'.join(row)


board=TicTacToe()
while True:
  board.print_()
  while True:
    loc=raw_input("Please provide a location: ")
    try:
      board.human(loc)
      break
    except:
      pass
  board.print_()
  print '------'
  board.ai()
  board.print_()
  print '------'
  # break
