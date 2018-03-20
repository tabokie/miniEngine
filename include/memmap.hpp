#ifndef DISC_MEMMAP_HPP_
#define DISC_MEMMAP_HPP_

#include <string>
#include <iostream>

#ifdef __WIN64
#include <windows.h>
#endif

#ifdef __WIN32
#include <windows.h>
#endif

#ifdef __linux
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#endif

namespace disc_reader{

#if defined(__WIN64) || defined(__WIN32)

namespace win_mmap{

class MemMap{

 public:
	MemMap():file_opened(false),file_mapped(false),ptr_(nullptr){}
	MemMap(const char* file_name):file_opened(false),file_mapped(false),ptr_(nullptr){Open(file_name);}
	~MemMap(){
		Close();
	}

	bool Open(const char* file_name){
		if(file_opened)return false;
		file_handle_ = CreateFile(file_name ,GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
		file_opened = true;
		return true;
	}
	bool Map(const char* map_name){
		if(file_mapped)return false;
		if(!file_opened)return false;
		map_handle_ = CreateFileMapping(file_handle_, NULL, PAGE_READONLY, 0, 0, map_name);
		if(map_handle_ == INVALID_HANDLE_VALUE){
			Error_();
		}
		ptr_ = (char*)MapViewOfFile(map_handle_, FILE_MAP_READ, 0, 0, 0);
		if(ptr_ == NULL){
			Error_();
		}
		file_mapped = true;
		return true;
	}
	bool Share(const char* map_name){
		if(file_mapped)return false;
		map_handle_ = OpenFileMapping(PAGE_READONLY, FALSE, map_name);
		if(map_handle_ == INVALID_HANDLE_VALUE){
			Error_();
		}
		ptr_ = (char*)MapViewOfFile(map_handle_, FILE_MAP_READ, 0, 0, 0);
		if(ptr_ == NULL){
			Error_();
		}
		return true;
	}
	bool Close(void){
		if(file_mapped)
			Unmap_();
		if(file_opened)
			Unfile_();
		return true;
	}
	char* get_ptr(){
		if(ptr_ == NULL)return nullptr;
		return ptr_;
	}

	std::string get_str(){
		if(ptr_ == NULL)return std::string("");
		return std::string(ptr_);
	}

 private:

	HANDLE file_handle_;
	bool file_opened;
	HANDLE map_handle_;
	bool file_mapped;
	char* ptr_;
	void Unmap_(){
		if(!UnmapViewOfFile(ptr_) || !CloseHandle(map_handle_)){
			Error_();
		}
		file_mapped = false;
	}
	void Unfile_(){
		if(!CloseHandle(file_handle_)){
			Error_();
		}
		file_opened = false;
	}
	void Error_(void){
		std::cout << GetLastError() << std::endl << std::flush;
		exit(0);
	}


};


} /* namespace win_mmap */

using namespace win_mmap;

#endif /* __WINXX */



#if defined(__linux)

namespace linux_mmap{

class MemMap{

 public:
	MemMap():file_opened(false),file_mapped(false),ptr_(nullptr){}
	MemMap(const char* file_name):file_opened(false),file_mapped(false),ptr_(nullptr){Open(file_name);}
	~MemMap(){
		Close();
	}

	bool Open(const char* file_name){
		if(file_opened)return false;
		struct stat sb;
		f_id = open(file_name, O_RDONLY | O_CREAT, S_IRUSR);
		if(f_id==-1 || fstat(f_id, &sb)==-1)return false;
		file_size = sb.st_size;
		file_opened = true;
		return true;
	}
	bool Map(const char* map_name){
		if(file_mapped)return false;
		if(!file_opened)return false;
		ptr_ = (char*)mmap(NULL, file_size,PROT_READ, MAP_SHARED, fd, 0);
		if(ptr_ == NULL){
			Error_();
		}
		file_mapped = true;
		return true;
	}
	bool Close(void){
		if(file_mapped)
			Unmap_();
		if(file_opened)
			Unfile_();
		return true;
	}
	char* get_ptr(){
		if(ptr_ == NULL)return nullptr;
		return ptr_;
	}

	std::string get_str(){
		if(ptr_ == NULL)return std::string("");
		return std::string(ptr_);
	}

 private:

	int f_id;
	bool file_opened;
	bool file_mapped;
	size_t file_size;
	char* ptr_;
	void Unmap_(){
		if((munmap(ptr_, file_size*sizeof(char))) == -1){
			Error_();
		}
		file_mapped = false;
	}
	void Unfile_(){
		if(close(f_id) == -1){
			Error_();
		}
		file_opened = false;
	}
	void Error_(void){
		exit(0);
	}


};

} /* namespace linux_mmap */

using namespace linux_mmap;

#endif /* __linux */


} /* namespace disc_helper */


#endif /* DISC_MEMMAP_HPP_ */

