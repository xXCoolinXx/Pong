CXX = g++
source = src/Source/*
objects = target/obj/* 
dependencies = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
name = Pong

all: target/$(name)


target/$(name): $(objects) $(dependencies)
	$(CXX) -o $(name) $(objects) $(dependencies)
	mv $(name) target/exe/

$(objects): $(source)
	$(CXX) -c $(source)
	mv *.o target/obj