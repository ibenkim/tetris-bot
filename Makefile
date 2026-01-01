CXX = g++
CXXFLAGS = -g -Wall -std=c++11

TARGET = tetris

SRCS = main.cpp game.cpp board.cpp piece.cpp Tpiece.cpp Lpiece.cpp #Zpiece.cpp

OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp 
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean: 
	rm -f $(OBJS) $(TARGET)
