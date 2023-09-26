output: bin/main.o bin/AesFunctions.o bin/Utils.o bin/AesKeyExpand.o bin/AESCipher.o
	g++ bin/main.o bin/AesFunctions.o bin/Utils.o bin/AesKeyExpand.o bin/AESCipher.o  -o bin/output

bin/main.o: main.cpp 
	g++ -c main.cpp -o bin/main.o

bin/AesFunctions.o: AES/AesFunctions.cpp AES/AesFunctions.hpp 
	g++ -c AES/AesFunctions.cpp -o bin/AesFunctions.o

bin/Utils.o: AES/Utils.cpp AES/Utils.hpp 
	g++ -c AES/Utils.cpp -o bin/Utils.o

bin/AesKeyExpand.o: AES/AesKeyExpand.cpp AES/AesKeyExpand.hpp
	g++ -c AES/AesKeyExpand.cpp -o bin/AesKeyExpand.o

bin/AESCipher.o: AES/AESCipher.cpp AES/AESCipher.hpp
	g++ -c AES/AESCipher.cpp -o bin/AESCipher.o

run: output
	bin/output

clean_bin:
	del bin\*.o bin\output.exe