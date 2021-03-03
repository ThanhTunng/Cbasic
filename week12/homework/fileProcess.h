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
