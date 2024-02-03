#ifndef CAT_H_
#define CAT_H_ 1

class Cat{
  private:
    bool happy = true;

  public:
    void speak();
    void makeHappy();
    void makeSad();
    Cat();
    ~Cat();
 };

#endif // CAT_H_ 