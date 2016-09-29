
//Roosevelt Bannerman
//Microprocessor Program
#include <iostream>
#include <cmath>

const int
   NUMINSTRUCTIONS = 8,
   REGISTERSIZE = 32,
   MEMORYSIZE = 128;
int PC = 0;

std::string instructions[NUMINSTRUCTIONS] = //Enter 8-Bit Hex Instructions Here
   {"2062003E","2041FFF9","00221822","00222020","00222824","AD010007","8D090007","15090011"};
//   0          1           2          3          4          5          6          7

std::string registers[REGISTERSIZE] = //32 Register Locations
   {"00000000","00000000","00000000","00000000","00000000","00000000","00000000","00000000",
//   $0         $1         $2         $3         $4         $5         $6         $7
    "00000000","00000000","00000000","00000000","00000000","00000000","00000000","00000000",
//   $8         $9         $10        $11        $12        $13        $14        $15
    "00000000","00000000","00000000","00000000","00000000","00000000","00000000","00000000",
//   $16        $17        $18        $19        $20        $21        $22        $23
    "00000000","00000000","00000000","00000000","00000000","00000000","00000000","00000000"};
//   $24        $25        $26        $27        $28        $29        $30        $31

std::string memory[MEMORYSIZE] = //128 Memory Locations
   {"00000000","00000000","00000000","00000000","00000000","00000000","00000000","00000000",
//   M0         M1         M2         M3          M4        M5         M6         M7
    "00000000","00000000","00000000","00000000","00000000","00000000","00000000","00000000",
//   M8         M9         M10        M11        M12        M13        M14        M15
    "00000000","00000000","00000000","00000000","00000000","00000000","00000000","00000000",
//   M16        M17        M18        M19        M20        M21        M22        M23
    "00000000","00000000","00000000","00000000","00000000","00000000","00000000","00000000",
//   M24        M25        M26        M27        M28        M29        M30        M31
    "00000000","00000000","00000000","00000000","00000000","00000000","00000000","00000000",
//   M32        M33        M34        M35        M36        M37        M38        M39
    "00000000","00000000","00000000","00000000","00000000","00000000","00000000","00000000",
//   M40        M41        M42        M43        M44        M45        M46        M47
    "00000000","00000000","00000000","00000000","00000000","00000000","00000000","00000000",
//   M48        M49        M50        M51        M52        M53        M54        M55
    "00000000","00000000","00000000","00000000","00000000","00000000","00000000","00000000",
//   M56        M57        M58        M59        M60        M61        M62        M63
    "00000000","00000000","00000000","00000000","00000000","00000000","00000000","00000000",
//   M64        M65        M66        M67        M68        M69        M70        M71
    "00000000","00000000","00000000","00000000","00000000","00000000","00000000","00000000",
//   M72        M73        M74        M75        M76        M77        M78        M79
    "00000000","00000000","00000000","00000000","00000000","00000000","00000000","00000000",
//   M80        M81        M82        M83        M84        M85        M86        M87
    "00000000","00000000","00000000","00000000","00000000","00000000","00000000","00000000",
//   M88        M89        M90        M91        M92        M93        M94        M95
    "00000000","00000000","00000000","00000000","00000000","00000000","00000000","00000000",
//   M96        M97        M98        M99        M100       M101       M102       M103
    "00000000","00000000","00000000","00000000","00000000","00000000","00000000","00000000",
//   M104       M105       M106       M107       M108       M109       M110       M111
    "00000000","00000000","00000000","00000000","00000000","00000000","00000000","00000000",
//   M112       M113       M114       M115       M116       M117       M118       M119
    "00000000","00000000","00000000","00000000","00000000","00000000","00000000","00000000"};
//   M120       M121       M122       M123       M124       M125       M126       M127

//{ Function Declarations
std::string
   hexToUnsign(std::string),
   charConvertor(char),
   runAdd(int,int),
   runSub(int,int),
   runAnd(int,int),
   runOr(int,int),
   runXor(int,int),
   runSlt(int,int),
   runAddi(int,std::string),
   runSlti(int,std::string),
   calculateAd(std::string),
   calculateJump(std::string,char),
   resultToHex(std::string),
   signExtension(std::string);

char
   binToHex(std::string);
int
   calculateRs(std::string),
   calculateRt(std::string),
   calculateRd(std::string),
   calculateSh(std::string),
   calculateFn(std::string),
   addressToInt(std::string);
void
   calculateOp(std::string),
   runRType(std::string),
   runIType(std::string, int),
   runJType(std::string,char),
   writeResult(std::string,int),
   runLW(std::string,int),
   runSW(std::string,int),
   runBeq(int,int,std::string),
   runBne(int,int,std::string),
   displayRegister(),
   displayMemory(),
   runStart(),
   runInstructions(),
   runEnd(),
   obtainInstructions();
//}

int main(){
   runStart();

   //obtainInstructions();

   runInstructions();

   runEnd();
}

void runInstructions(){

   std::cout << "\n\n\n\n\t~~~~~~~~~~~~~~~~~~~~~~Instructions~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
   for(;PC<NUMINSTRUCTIONS;PC++){ //Iterates through the instructions
      std::string currentHexadecimal = instructions[PC]; //Calls current instuction
      std::string currentInstruction = hexToUnsign(currentHexadecimal); //Converts the instruction to binary
      calculateOp(currentInstruction); //Calculates the Op code of the instruction and runs the instruction
   }
}

std::string hexToUnsign(std::string hexString){
   std::string unsignString;

   const int LENGTH = hexString.length();

   for(int i=0;i<LENGTH;i++){
      unsignString += charConvertor(hexString[i]);
      //Converts each hex character to it's 4 bit binary equalivalent then puts them together in a string
   }

   return unsignString; //Returns the binary string

}

std::string charConvertor(char hexChar){
   switch(hexChar){//Converts each hex character to it's 4 bit binary equalivalent
      case '0':{
         return "0000";
      }
      case '1':{
         return "0001";
      }
      case '2':{
         return "0010";
      }
      case '3':{
         return "0011";
      }
      case '4':{
         return "0100";
      }
      case '5':{
         return "0101";
      }
      case '6':{
         return "0110";
      }
      case '7':{
         return "0111";
      }
      case '8':{
         return "1000";
      }
      case '9':{
         return "1001";
      }
      case 'A':{
         return "1010";
      }
      case 'B':{
         return "1011";
      }
      case 'C':{
         return "1100";
      }
      case 'D':{
         return "1101";
      }
      case 'E':{
         return "1110";
      }
      case 'F':{
         return "1111";
      }
   }
   return 0;
}

void runRType(std::string instruction){
   int //Calculates all the R-type parts
      rs = calculateRs(instruction),
      rt = calculateRt(instruction),
      rd = calculateRd(instruction),
    //sh = calculateSh(instruction),
      fn = calculateFn(instruction);
   switch(fn){ //Runs instruction depending on fn code
      case 32:{//add
         std::string result = runAdd(rs,rt);
         writeResult(result,rd);
         std::cout << "\n\tInstruction " << PC+1 << ": " << instructions[PC] <<
         " - " << "add  $" << rd << ", $" << rs << ", $" << rt;
         break;
      }
      case 34:{//sub
         std::string result = runSub(rs,rt);
         writeResult(result,rd);
         std::cout << "\n\tInstruction " << PC+1 << ": " << instructions[PC] <<
         " - " << "sub  $" << rd << ", $" << rs << ", $" << rt;
         break;
      }
      case 36:{//and
         std::string result = runAnd(rs,rt);
         writeResult(result,rd);
         std::cout << "\n\tInstruction " << PC+1 << ": " << instructions[PC] <<
         " - " << "and  $" << rd << ", $" << rs << ", $" << rt;
         break;
      }
      case 37:{//or
         std::string result = runOr(rs,rt);
         writeResult(result,rd);
         std::cout << "\n\tInstruction " << PC+1 << ": " << instructions[PC] <<
         " - " << "or   $" << rd << ", $" << rs << ", $" << rt;
         break;
      }
      case 38:{//xor
         std::string result = runXor(rs,rt);
         writeResult(result,rd);
         std::cout << "\n\tInstruction " << PC+1 << ": " << instructions[PC] <<
         " - " << "xor  $" << rd << ", $" << rs << ", $" << rt;
         break;
      }
      case 42:{//slt
         std::string result = runSlt(rs,rt);
         writeResult(result,rd);
         std::cout << "\n\tInstruction " << PC+1 << ": " << instructions[PC] <<
         " - " << "slt  $" << rd << ", $" << rs << ", $" << rt;
      }
   }
}

void runIType(std::string instruction, int opCode){
   int
      op = opCode,
      rs = calculateRs(instruction),
      rt = calculateRt(instruction);
   std::string ad = calculateAd(instruction);
   switch(op){//Runs instruction depending on op code
      case 4:{//beq
         runBeq(rs,rt,ad);
         std::cout << "\n\tInstruction " << PC+1 << ": " << instructions[PC] <<
         " - " << "beq  $" << rs << ", $" << rt << ", " << addressToInt(ad);
         break;
      }
      case 5:{//bne
         runBne(rs,rt,ad);
         std::cout << "\n\tInstruction " << PC+1 << ": " << instructions[PC] <<
         " - " << "bne  $" << rs << ", $" << rt << ", " << addressToInt(ad);
         break;
      }
      case 8:{//addi
         std::string result = runAddi(rs,ad);
         writeResult(result,rt);
         std::cout << "\n\tInstruction " << PC+1 << ": " << instructions[PC] <<
         " - " << "addi $" << rt << ", $" << rs << ", " << addressToInt(ad);
         break;
      }
      case 10:{//slti
         std::string result = runSlti(rs,ad);
         writeResult(result,rt);
         std::cout << "\n\tInstruction " << PC+1 << ": " << instructions[PC] <<
         " - " << "slti $" << rt << ", $" << rs << ", " << addressToInt(ad);
         break;
      }
      case 35:{//lw
         std::string result = runAddi(rs,ad);
         runLW(result,rt);
         std::cout << "\n\tInstruction " << PC+1 << ": " << instructions[PC] <<
         " - " << "lw   $" << rt << ", " << addressToInt(ad) << "($" << rs << ")";
         break;
      }
      case 43:{//sw
         std::string result = runAddi(rs,ad);
         runSW(result,rt);
         std::cout << "\n\tInstruction " << PC+1 << ": " << instructions[PC] <<
         " - " << "sw   $" << rt << ", " << addressToInt(ad) << "($" << rs << ")";
      }
   }
}

void runJType(std::string instruction,char ext){
   std::string jump = calculateJump(instruction,ext);

   std::string hexVersion = resultToHex(jump);

   for(int i=0;i<NUMINSTRUCTIONS;i++){
      if(hexVersion == instructions[i]){ //Checks if the jump address matches any instruction values
         PC = i;                         //It it matches jumps the PC to that address
      }
   }

   std::cout << "\n\tInstruction " << PC+1 << ": " << instructions[PC] <<
         ": " << "j " << jump;

}

void calculateOp(std::string instruction){
   int
      opCode = 0,
      counter = 0;

   for(int i=5;i>-1;i--){ //Calculates the op code
      opCode += (instruction[i] - '0') * pow(2,counter);
      counter++;
   }

   if(opCode == 0){ //Runs R-type if op is 0
      runRType(instruction);
   }
   else if(opCode == 2){
      runJType(instruction,instruction[0]);
   }
   else{ //Runs I-type otherwise
      runIType(instruction, opCode);
   }
}

int calculateRs(std::string instruction){
   int rsCode = 0;
   int counter = 0;

   for(int i=10;i>5;i--){ //Calculates rs code
      rsCode += (instruction[i] - '0') * pow(2,counter);
      counter++;
   }

   return rsCode;
}

int calculateRt(std::string instruction){
   int rtCode = 0;
   int counter = 0;

   for(int i=15;i>10;i--){ //Calculates rt code
      rtCode += (instruction[i] - '0') * pow(2,counter);
      counter++;
   }

   return rtCode;
}

int calculateRd(std::string instruction){
   int rdCode = 0;
   int counter = 0;

   for(int i=20;i>15;i--){ //Calculates rd code
      rdCode += (instruction[i] - '0') * pow(2,counter);
      counter++;
   }

   return rdCode;
}

int calculateSh(std::string instruction){
   int shCode = 0;
   int counter = 0;

   for(int i=25;i>20;i--){ //Calculates sh code
      shCode += (instruction[i] - '0') * pow(2,counter);
      counter++;
   }
   return shCode;
}

int calculateFn(std::string instruction){
   int fnCode = 0;
   int counter = 0;

   for(int i=31;i>25;i--){ //Calculates fn code
      fnCode += (instruction[i] - '0') * pow(2,counter);
      counter++;
   }
   return fnCode;
}

std::string calculateAd(std::string instruction){
   std::string adCode;

   for(int i=16;i<32;i++){ //Calculates the label code
      adCode += instruction[i];
   }

   return adCode;
}

std::string calculateJump(std::string instruction, char extender){
   std::string jCode;

   for(int i=6;i<32;i++){ //Calculates jump address
      jCode += instruction[i];
   }

   jCode += "00"; //Adds extends j code to 28 bits

   std::string extension = charConvertor(extender);

   jCode = extension + jCode;

   return jCode;
}

std::string runAdd(int rs,int rt){
   std::string
      leftOp = hexToUnsign(registers[rs]),
      rightOp = hexToUnsign(registers[rt]),
      result;
   const int LENGTH = leftOp.size();

   for(int i=0;i<LENGTH;i++){//Sums the left and right operands
      result += (((leftOp[i]) - '0') + ((rightOp[i]) - '0') + '0');
   }

   for(int i = (LENGTH-1);i>-1;i--){ //Distributes any 2s in result
      if(result[i] == '2'){
         result[i] = '0';
         result[i-1] = ((result[i-1]-'0') + 1) + '0';
      }
      else if( result[i] == '3'){
            result[i] = '1';
            result[i-1] = ((result[i-1]-'0') + 1) + '0';
      }
   }
   return result;
}

std::string runSub(int rs,int rt){
    std::string
      leftOp = hexToUnsign(registers[rs]),
      rightOp = hexToUnsign(registers[rt]),
      result;
   const int LENGTH = leftOp.size();

   for(int i=0;i<LENGTH;i++){ //Inverse the right operand
      if(rightOp[i]== '0'){
         rightOp[i] = '1';
      }
      else{
      rightOp[i] = '0';
      }
   }

   rightOp[LENGTH-1] = ((rightOp[LENGTH-1]-'0') + 1) + '0'; //Adds 1 to the right operand

   for(int i = (LENGTH-1);i>-1;i--){ //Distributes any 2s in the right operand
      if( rightOp[i] == '2'){
         rightOp[i] = '0';
         rightOp[i-1] = ((rightOp[i-1]-'0') + 1) + '0';
      }
   }

   for(int i=0;i<LENGTH;i++){//Sums the left operand and twos complement of right operand
      result += (((leftOp[i]) - '0') + ((rightOp[i]) - '0') + '0');
   }

   for(int i = (LENGTH-1);i>-1;i--){ //Distributes any 2s in result
      if(result[i] == '2'){
         result[i] = '0';
         result[i-1] = ((result[i-1]-'0') + 1) + '0';
      }
      else if( result[i] == '3'){
            result[i] = '1';
            result[i-1] = ((result[i-1]-'0') + 1) + '0';
      }
   }

   return result;
}

std::string runAnd(int rs,int rt){
   std::string
      leftOp = hexToUnsign(registers[rs]),
      rightOp = hexToUnsign(registers[rt]),
      result;
   const int LENGTH = leftOp.size();
   for(int i=0;i<LENGTH;i++){ //Ands the left and right operands
      if(leftOp[i] == '1' && rightOp[i] == '1')
         result += '1';
      else{
         result += '0';
      }
   }
   return result;
}

std::string runOr(int rs,int rt){
   std::string
      leftOp = hexToUnsign(registers[rs]),
      rightOp = hexToUnsign(registers[rt]),
      result;
   const int LENGTH = leftOp.size();
   for(int i=0;i<LENGTH;i++){ //Ors the left and right operands
      if(leftOp[i] == '0' && rightOp[i] == '0')
         result += '0';
      else{
         result += '1';
      }
   }
   return result;
}

std::string runXor(int rs,int rt){
   std::string
      leftOp = hexToUnsign(registers[rs]),
      rightOp = hexToUnsign(registers[rt]),
      result;
   const int LENGTH = leftOp.size();

   for(int i=0;i<LENGTH;i++){ //Xors the left and right operands
      if((leftOp[i] == '1') && (rightOp[i] == '0')){
         result += '1';
      }
      else if((leftOp[i] == '0') && (rightOp[i] == '1')){
         result += '1';
      }
      else{
         result += '0';
      }
   }

   return result;
}

std::string runSlt(int rs, int rt){
   std::string
      leftOp = hexToUnsign(registers[rs]),
      rightOp = hexToUnsign(registers[rt]),
      result;
   int
      left = addressToInt(leftOp),
      right = addressToInt(rightOp);

   if(left < right){ //Returns 1 if rs is less than rt

      result = "00000000000000000000000000000001";
   }
   else{ //Otherwise returns 0
      result = "00000000000000000000000000000000";
   }
   return result;
}

std::string runAddi(int rs,std::string ad){
   std::string
      leftOp = hexToUnsign(registers[rs]),
      rightOp = signExtension(ad),
      result,
      extension;

   const int LENGTH = leftOp.size();

   for(int i=0;i<LENGTH;i++){ //Adds the left operand to the ad code
         result += (((leftOp[i]) - '0') + ((rightOp[i]) - '0') + '0');
   }

   for(int i = (LENGTH-1);i>-1;i--){ //Distributes any 2s in the result
      if(result[i] == '2'){
         result[i] = '0';
         result[i-1] = ((result[i-1]-'0') + 1) + '0';
      }
      else if(result[i] == '3'){
         result[i] = '1';
         result[i-1] = ((result[i-1]-'0') + 1) + '0';
      }
   }

   if(result[0] == '1'){
      for(int i=0;i<LENGTH;i++){ //Inverse the result
         if(result[i]== '0'){
            result[i] = '1';
         }
         else{
         result[i] = '0';
         }
      }

      result[LENGTH-1] = ((result[LENGTH-1]-'0') + 1) + '0'; //Adds 1 to the result

      for(int i = (LENGTH-1);i>-1;i--){ //Distributes any 2s in the result
         if( result[i] == '2'){
            result[i] = '0';
            result[i-1] = ((result[i-1]-'0') + 1) + '0';
         }
         else if( result[i] == '3'){
            result[i] = '1';
            result[i-1] = ((result[i-1]-'0') + 1) + '0';
         }
      }
   }

   return result;
}

std::string runSlti(int rs, std::string ad){
  std::string
      leftOp = hexToUnsign(registers[rs]),
      result;
   int
      left = addressToInt(leftOp),
      right = addressToInt(ad);

   if(left < right){ //Returns 1 if rs is less than the ad code
      result = "00000000000000000000000000000001";
   }
   else{ //Otherwise returns 0
      result = "00000000000000000000000000000000";
   }
   return result;
}

std::string signExtension(std::string original){

   std::string result;
   std::string extension;
   char extender = original[0];
   const int LENGTH = original.size();

   for(int i=LENGTH;i<32;i++){ //Extends binary to 32 bits
      extension += extender;
   }

   result = extension + original;

   return result;
}

void runLW(std::string result,int rt){

   int total = addressToInt(result);

   registers[rt] = memory[total]; //Stores memory location at the result in register rt
}

void runSW(std::string result,int rt){

   int total = addressToInt(result);

   memory[total] = registers[rt]; //Stores the value in register rt in memory location at the result
}

void runBeq(int rs,int rt,std::string ad){
   std::string
      leftOp = registers[rs],
      rightOp = registers[rt];

   if(leftOp == rightOp){ //Adds label to PC if registers are equal
      int label = addressToInt(ad);
      PC += label;
      PC--;
   }

}

void runBne(int rs,int rt,std::string ad){
   std::string
      leftOp = registers[rs],
      rightOp = registers[rt];

   if(leftOp != rightOp){ //Adds label to PC if registers are not equal
      int label = addressToInt(ad);
      PC += label;
      PC--;
   }
}

void writeResult(std::string result,int writeLocation){

   std::string hexVersion = resultToHex(result); //Converts the 16-bit result into 4-bit hex

   registers[writeLocation] = hexVersion; //Writes the 4-bit result into the write location
}

int addressToInt(std::string address ){

   int total = 0;
   int counter = 0;
   const int LENGTH = address.size();
   bool isNeg = false;

   if(address[0] == '1'){
         isNeg = true;
         for(int i=0;i<LENGTH;i++){ //Inverse the right operand
         if(address[i]== '0'){
            address[i] = '1';
         }
         else{
         address[i] = '0';
         }
      }

      address[LENGTH-1] = ((address[LENGTH-1]-'0') + 1) + '0'; //Adds 1 to the right operand

      for(int i = (LENGTH-1);i>-1;i--){ //Distributes any 2s in the right operand
         if( address[i] == '2'){
            address[i] = '0';
            address[i-1] = ((address[i-1]-'0') + 1) + '0';
         }
      }





   //-------------------------------------------
   }



   for(int i=LENGTH-1;i>-1;i--){ //Converts the result into an integer
      total += (address[i] - '0') * (pow(2,counter));
      counter++;
   }

   if(isNeg){
      total *= -1;
   }
   return total;
}

std::string resultToHex(std::string result){

   std::string hexVersion;
   std::string group;

   const int LENGTH = result.size();

   for(int i=0;i<LENGTH;i+=4){ //Converts each byte into it's equalivalent hex character
      for(int ii=i;ii<i+4;ii++){
         group += result[ii];
      }
      hexVersion += binToHex(group);
      group.clear();
   }
   return hexVersion;
}

void displayRegister(){

   std::cout << "\n\n\t\t-------------Current Registers-------------" << std::endl;
   for(int i=0;i<(REGISTERSIZE/4);i++){ //Displays what the registers currently looks like.
      std::cout << "\n\t$" << i << " - " << registers[i];
      if(i+8 == 8 || i+8 == 9){
         std::cout << "\t$" << i+8 << "  - " << registers[i+8];
      }
      else{
      std::cout << "\t$" << i+8 << " - " << registers[i+8];
      }
      std::cout << "\t$" << i+16 << " - " << registers[i+16];
      std::cout << "\t$" << i+24 << " - " << registers[i+24];
   }
   std::cout << std::endl;
}

void displayMemory(){

   std::cout << "\n\n\t\t-------------Current Memory-------------" << std::endl;
    for(int i=0;i<(MEMORYSIZE/4);i++){ //Displays what the memory currently looks like.
      if(i < 10){
         std::cout << "\n\tM" << i << "  - " << memory[i];
      }
      else{
         std::cout << "\n\tM" << i << " - " << memory[i];
      }
      std::cout << "\tM" << i+32 << " - " << memory[i+32];
      std::cout << "\tM" << i+64 << " - " << memory[i+64];
      if(i+96 < 100){
         std::cout << "\tM" << i+96 << "  - " << memory[i+96];
      }
      else{
         std::cout << "\tM" << i+96 << " - " << memory[i+96];
      }
   }
   std::cout << std::endl;
}

char binToHex(std::string convert){
   //Converts every 4 bits into it's equalivalent hex character
   if(convert == "0000"){
      return '0';
   }
   else if(convert == "0001"){
      return '1';
   }
   else if(convert == "0010"){
      return '2';
   }
   else if(convert == "0011"){
      return '3';
   }
   else if(convert == "0100"){
      return '4';
   }
   else if(convert == "0101"){
      return '5';
   }
   else if(convert == "0110"){
      return '6';
   }
   else if(convert == "0111"){
      return '7';
   }
   else if(convert == "1000"){
      return '8';
   }
   else if(convert == "1001"){
      return '9';
   }
   else if(convert == "1010"){
      return 'A';
   }
   else if(convert == "1011"){
      return 'B';
   }
   else if(convert == "1100"){
      return 'C';
   }
   else if(convert == "1101"){
      return 'D';
   }
   else if(convert == "1110"){
      return 'E';
   }
   else if(convert == "1111"){
      return 'F';
   }
   return 0;
}

void runStart(){
   //Displays register and memory locations before instructions are ran
   std::cout << "\n\n\t~~~~~~~~~~~~~~~~~~~Before Instructions~~~~~~~~~~~~~~~~~~~";
   displayRegister();
   displayMemory();

}

void runEnd(){
   //Displays register and memory locations after instructions are ran
   std::cout << "\n\n\n\n\t~~~~~~~~~~~~~~~~~~~After Instructions~~~~~~~~~~~~~~~~~~~";
   displayRegister();
   displayMemory();

   std::cout << std::endl << std::endl;

}

void obtainInstructions(){

   std::cout << "\n\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
   for(int i=0;i<NUMINSTRUCTIONS;i++){
      std::cout << "\n\tPlease enter instruction " << i+1 << ": ";
      std::cin >> instructions[i];
   }
}
