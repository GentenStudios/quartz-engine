
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
// this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimer in the documentation
// and/or other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors
// may be used to endorse or promote products derived from this software without
// specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#include <Quartz/Utilities/Commander.hpp>
#include <iostream>

int doSomethingA(std::array<std::string, qz::utils::MaxArgumentNumber> argv){std::cout << "Did thing A \n"; return 0;}
int doSomethingB(std::array<std::string, qz::utils::MaxArgumentNumber> argv){std::cout << "Did thing B \n"; return 0;}
int doSomethingC(std::array<std::string, qz::utils::MaxArgumentNumber> argv){std::cout << "Did thing C \n"; return 0;}
int printSomething(std::array<std::string, qz::utils::MaxArgumentNumber> args){
	std::cout << args[0]; return 0;}

int main(){
	std::cout << "Program Started \n";
	qz::utils::Commander Commander = qz::utils::Commander();

	Commander.reg("doSomething", "Does thing A", "none", &doSomethingA);
	Commander.reg("doSomethingB", "Does thing B","none", &doSomethingB);
	Commander.reg("doSomething", "Does thing C", "none", &doSomethingC);
	Commander.reg("print", "Prints first argument", "none", &printSomething);

	std::cout << "Searching for \"doSomething\"\n";
	std::cout << "found in index: " + std::to_string(Commander.find("doSomething")) + "\n";

	Commander.post();
	
}
