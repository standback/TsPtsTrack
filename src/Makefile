INCLUDE += -I../include
SRC += TsReader.cpp TsPtsTrack.cpp
OBJ += TsReader.o TsPtsTrack.o
PRGRAM = tsPtsTrack
CPPFLAGS += $(INCLUDE) -g	
	
All: $(OBJ)
	g++ $(OBJ) -o $(PRGRAM)
$(OBJ) : $(SRC)


clean:
	rm *.o $(PRGRAM)
