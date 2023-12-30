CC = g++
CFLAGS = -Wall -I include -I SDL/include
LDFLAGS = -L lib -L SDL/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image

SRCDIR = src
OBJDIR = obj

SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))

darkwood-quest: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(OBJDIR)/*.o darkwood-quest.exe

