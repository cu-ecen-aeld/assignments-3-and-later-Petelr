writer: writer.c
	gcc writer.c -o writer
CROSS_COMPILE: writer.c
	aarch64-none-linux-gnu-gcc writer.c -o writer
	mkdir -p assignments/assignment2
	touch assignments/assignment2/fileresult.txt
	file writer > assignments/assignment2/fileresult.txt
clean:
	rm -rf writer *.o *.out assignments