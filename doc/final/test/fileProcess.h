
int countLines(char * textFile){
  FILE * f = fopen(textFile, "r");
  char c;
  int count = 0;
  while((c=fgetc(f))!=EOF){
    if(c=='\n') count++;
  }
  fclose(f);
  return count;
}
/*
void readDataFromTextFile(char * textFile,int count){
  FILE * fr = fopen("phoneDB.txt", "r");
  if(fr==NULL){
    printf("Cannot open phoneDB.txt\n");
    return;
  }
  
  while(!feof(fr)){
    Phone * list = (Phone *)malloc(sizeof(Phone));
    
    fscanf(fr , "%s%s%f%s", list->model, list->memory, &(list->display), list->price);
    insertEnd(list);
    
  }
  fclose(fr);
}
/*
void readDataFromDatFile(char * datFile, Phone * phone){
  FILE* fr = fopen("phoneDB.dat", "rb");
  if(fr==NULL){
    printf("Cannot open phoneDB.dat\n");
    return;
  }

  while(!feof(fr)){
    phone = (Phone *)malloc(sizeof(Phone));
    fread(phone,sizeof(Phone),1,fr);
    insertEnd(phone);
  }
  free(phone);
  fclose(fr);
  }*/
/*
void splitFileDat(char *fin, int size, int n, char *fno1, char *fno2) {

	if (n > size) {
		printf("n Over the number of phones\n");
		return;
	}
	
	FILE *fi = fopen(fin, "rb");

	if (fi == NULL) {
		printf("Can not open file \n");
		return;
	}

	FILE *f1 = fopen(fno1, "w+b");
	FILE *f2 = fopen(fno2, "w+b");

	type temp;
	for (int i = 0; i < n; i++) {
		fread(&temp, sizeof(type), 1, fi);
		fwrite(&temp, sizeof(type), 1, f1);
	}

	fread(&temp, sizeof(type), 1, fi);	
	while ( !feof(fi) ) {
		fwrite(&temp, sizeof(type), 1, f2);
		fread(&temp, sizeof(type), 1, fi);
	}

	fclose(fi);
	fclose(f1);
	fclose(f2);
	return;
}

void mergeFileDat(char *fIn1, char *fIn2, char *fO) {

	FILE *fi1 = fopen(fIn1, "rb");
	FILE *fi2 = fopen(fIn2, "rb");

	if (fi1 == NULL || fi2 == NULL) {
		printf("Can not open file\n");
		return;
	}

	FILE *fo = fopen(fO, "w+b");

	type temp;

	fread(&temp, sizeof(type), 1, fi1);
	while ( !feof(fi1) ) {
		fwrite(&temp, sizeof(type), 1, fo);
		fread(&temp, sizeof(type), 1, fi1);
	}

	fread(&temp, sizeof(type), 1, fi2);
	while ( !feof(fi2) ) {
		fwrite(&temp, sizeof(type), 1, fo);
		fread(&temp, sizeof(type), 1, fi2);
	}
	
	fclose(fi1);
	fclose(fi2);
	fclose(fo);
	return;
}

void readFileDat(char *file){
	FILE *f = fopen(file, "rb");

	if (f == NULL) {
		printf("Can not open file %s \n", file);
		return;
	}

	SLLtype temp;

	fread(&temp, sizeof(type), 1, f);
	
	while ( !feof(f) ) {
		printf();
		fread(&temp, sizeof(type), 1, f);
	}
	
	fclose(f);
	return;
}
*/
