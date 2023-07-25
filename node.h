#ifndef node_h
#define node_h

class NODE{
	char data;
	NODE *nextPtr;
public:
	NODE(char);
	~NODE();
  char get_value();
	void set_next(NODE *);
	NODE* get_next();
};

typedef NODE* NodePtr;

NODE::NODE(char data){
	this->data = data;
	nextPtr = NULL;
}
char NODE::get_value(){
	return data;
}

NODE* NODE::get_next(){
	return nextPtr;
}

void NODE::set_next(NODE *nextPtr){
	 this->nextPtr=nextPtr;
}

NODE::~NODE(){

}


#endif