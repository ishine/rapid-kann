CC=			nvcc
CFLAGS=		-g -O2 -arch compute_60 -code sm_60
CFLAGS_LIB=	#-ansi -pedantic -Wno-long-long # ANSI C does not have inline which affects performance a little bit
CPPFLAGS=	-DHAVE_PTHREAD
INCLUDES=	-I.
EXE=		examples/mnist-cnn
LIBS=		-lpthread -lz -lm

ifdef CBLAS
	CPPFLAGS+=-DHAVE_CBLAS
	INCLUDES+=-I$(CBLAS)/include
	LIBS=-fopenmp -pthread -L$(CBLAS)/lib -lopenblas -lz -lm
endif

.SUFFIXES:.cu .o
.PHONY:all clean depend

.cu.o:
		$(CC) -c $(CFLAGS) $(INCLUDES) $(CPPFLAGS) $< -o $@

all:kautodiff.o kann.o kann_extra/kann_data.o $(EXE)

kautodiff.o:kautodiff.cu
		$(CC) -c $(CFLAGS) $(CFLAGS_LIB) $(INCLUDES) $(CPPFLAGS) -o $@ $<

kann.o:kann.cu
		$(CC) -c $(CFLAGS) $(CFLAGS_LIB) $(INCLUDES) $(CPPFLAGS) -o $@ $<

kann_extra/kann_data.o:kann_extra/kann_data.cu
		$(CC) -c $(CFLAGS) -DHAVE_ZLIB $< -o $@

examples/mnist-cnn:examples/mnist-cnn.o kautodiff.o kann.o kann_extra/kann_data.o
		$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
		rm -fr *.o */*.o a.out */a.out *.a *.dSYM */*.dSYM $(EXE)

depend:
		(LC_ALL=C; export LC_ALL; makedepend -Y -- $(CFLAGS) $(DFLAGS) -- *.cu kann_extra/*.cu examples/*.cu)

# DO NOT DELETE

kann.o: kann.cuh kautodiff.cuh
kautodiff.o: kautodiff.cuh
kann_extra/kann_data.o: kann_extra/kseq.cuh kann_extra/kann_data.cuh
examples/mnist-cnn.o: kann_extra/kann_data.cuh kann.cuh kautodiff.cuh
