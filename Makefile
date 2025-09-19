
CXX = g++
CXXFLAGS = -Wall
TARGET = mc 
SRC = mc.cpp
PREFIX = /usr/local

all: $(TARGET)


$(TARGET): $(SRC) 
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

install: $(TARGET)
	install -d $(DESTDIR)$(PREFIX)/bin
	install -m 755 $(TARGET) $(DESTDIR)$(PREFIX)/bin

uninstall: $(TARGET)
	rm -f $(DESTDIR)$(PREFIX)/bin/$(TARGET)
clean:
	rm -f $(TARGET)

