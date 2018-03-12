const int * lsearch(const int *first,const int *last, int value )
{
    while(*first != value and first != last){
        first++;
    }
    if(*first != value){
         return last;
     }else{
        return first;
     }
}

const int * bsearch(const int *first,const int *last, int value )
{
    auto size = last - first;
    auto pos  = ((size/2)-1);
    if(value == first[pos]){
        return &first[pos];
    }else if(value < pos){
        for(int i = 0; i < pos; i++){
            if(value == first[i]){
                return &first[i];
            }
        }
    }else{
        for(int i = (size/2); i < size; i++){
            if(value == first[i]){
                return &first[i];
            }
        }
    }
    return last;
}

const int * tsearch(const int *first,const int *last, int value )
{
    auto size = last - first;
    auto pos1  = (size/3);
    auto pos2 =  (2*pos1);
    if(value == first[pos1]){
        return &first[pos1];
    }else if(value == first[pos2]){
        return &first[pos2];
    }
    else if(value < pos1){
        for(int i = 0; i < pos1; i++){
            if(value == first[i]){
                return &first[i];
            }
        }
    }else if(value > pos1 and value < pos2){
        for(int i = pos1+1; i < pos2; i++){
            if(value == first[i]){
                return &first[i];
            }
        }
    }else{
        for(int i = pos2+1; i < size; i++){
            if(value == first[i]){
                return &first[i];
            }
        }
    }
    return last;
}
