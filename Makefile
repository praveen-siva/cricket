OBJECT_FILES= $(DEV_SRCS:.cpp=.o)

all: $(OBJECT_FILES)
	$(COMPILER) -g $(OBJECT_FILES) -o $(OUTPUT)

%.o: %.cpp
	$(COMPILER) $(CPPFLAGS) $(VPATH) -c $<

clean:
	rm -rf *.o $(OUTPUT)
