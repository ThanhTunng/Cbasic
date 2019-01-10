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
  FILE * fr = fopen("", "r");
  if(fr==NULL){
    printf("Cannot open .txt\n");
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
  FILE* fr = fopen("", "rb");
  if(fr==NULL){
    printf("Cannot open .dat\n");
    return;
  }

  while(!feof(fr)){
    phone = (Phone *)malloc(sizeof(Phone));
    fread(phone,sizeof(Phone),1,fr);
    SLLinsertLast(phone);
  }
  free(phone);
  fclose(fr);
  }*/
