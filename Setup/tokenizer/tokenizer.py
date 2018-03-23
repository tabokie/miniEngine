from bs4 import BeautifulSoup
import urllib
import re
import os

# data in upper path
path = os.path.join(os.path.dirname(__file__),"..")

# url obj with name
class url_object:
	def __init__(self,str0, str1):
		self.name = str0
		self.url = str1

# traverse father site
def Traverse(url_):
	head = ""
	# get head link
	for i in range(len(url_))[::-1]:
		if url_[i] == '/':
			head = url_[:i+1]
			break
	# open html raw
	raw = urllib.urlopen(url_).read()
	# parse links
	raw_sublinks = re.findall(r"(?<=href=\").+?(?=\")|(?<=href=\').+?(?=\')" ,raw)
	raw_sublinks += re.findall(r"(?<=HREF=\").+?(?=\")|(?<=HREF=\').+?(?=\')" ,raw)
	ret = []
	for link in raw_sublinks:
		if is_valid_link(link):
			ret.append(url_object(get_name(link),head+link))
	# return list of url_obj
	return ret

# get name of url link
def get_name(str):
	ret = []
	for i in str:
		if not i == '/': # clip off /
			ret.append(i)
	# convert to str
	ret = "".join(ret)
	while True:
		# clip off html
		idx = ret.find(".html")
		if idx == -1:
			break
		ret = ret[:idx]
	# return str
	return ret

# test if valid link
def is_valid_link(str):
	# mannually set
	ban_list = ["full.html", "/Shakespeare", "/shake.css"]
	if len(str) > 25 or str in ban_list :
		return False
	return True
#test if valid plain text
def is_valid_text(str):
	scope = 50
	head_str = str[:scope]
	if head_str.find("404") >= 0:
		return False
	return True
# get full name from site link name
def get_full_name(str):
	dict_ = {"allswell":"All's Well That Ends Well",
	"asyoulikeit":"As You Like It",
	"comedy_errors":"The Comedy of Errors" ,
	"cymbeline":"Cymbeline" ,
	"lll":"Love's Labours Lost" ,
	"measure":"Measure for Measure" ,
	"merry_wives":"The Merry Wives of Windsor" ,
	"merchant":"The Merchant of Venice" ,
	"midsummer":"A Midsummer Night's Dream" ,
	"much_ado":"Much Ado About Nothing" ,
	"pericles":"Pericles, Prince of Tyre" ,
	"taming_shrew":"Taming of the Shrew" ,
	"tempest":"The Tempest" ,
	"troilus_cressida":"Troilus and Cressida" ,
	"twelfth_night":"Twelfth Night" ,
	"two_gentlemen":"Two Gentlemen of Verona" ,
	"winters_tale":"Winter's Tale",
	"1henryiv":"Henry IV, part 1",
	"2henryiv":"Henry IV, part 2" ,
	"henryv":"Henry V" ,
	"1henryvi":"Henry VI, part 1",
	"2henryvi":"Henry VI, part 2" ,
	"3henryvi":"Henry VI, part 3" ,
	"henryviii":"Henry VIII" ,
	"john":"King John" ,
	"richardii":"Richard II" ,
	"richardiii":"Richard III",
	"cleopatra":"Antony and Cleopatra" ,
	"coriolanus":"Coriolanus" ,
	"hamlet":"Hamlet" ,
	"julius_caesar":"Julius Caesar" ,
	"lear":"King Lear" ,
	"macbeth":"Macbeth" ,
	"othello":"Othello" ,
	"romeo_juliet":"Romeo and Juliet" ,
	"timon":"Timon of Athens" ,
	"titus":"Titus Andronicus",
	"sonnet":"The Sonnets" ,
	"LoversComplaint":"A Lover's Complaint" ,
	"RapeOfLucrece":"The Rape of Lucrece" ,
	"VenusAndAdonis":"Venus and Adonis" ,
	"elegy":"Funeral Elegy by W.S."}
	if str.find('.')>=0:
		prefix = str[:str.find('.')]
		num_list = str.split('.')
		if len(num_list) == 2:
			full = full = dict_[prefix]+' '+num_list[1]+'.\n'
		else:
			full = dict_[prefix]+', '+'Act '+num_list[1]+', Scene '+num_list[2]+'.\n'
	else:
		full = dict_[str]+'.\n'
	return full

# tokenized file write
class Tokenizer:
	def __init__(self, str0, str1, str2, str3):
		# set path
		self.token_path = path+str0
		self.raw_path = path+str1
		self.manifest_path = path+str2
		self.meta_path = path+str3
		# reset info
		self.id = 0
		self.text = ""
		self.tokens = []
		self.manifest = []
		# clear file
		for p in [str0, str1, str2, str3]:
			if os.path.exists(p):
				os.remove(p)
	def run(self, name, txt):
		self.is_poem = True if name.find(".") == -1 or name.find("sonnet") >= 0 else False
		self.name = name
		print name # log
		self.text = txt
		self.id += 1
		self.clip() # clip redundent text
		self.write_meta() # write  id,name meta of text
		self.write_raw() # write text
		self.write_manifest() # write offset of text
		self.tokenize() # tokenize text
		self.write_token() # write tokens
	def clip(self):
		if self.is_poem:
			lines = 8
			for i in range(lines):
				idx = self.text.find('\n')
				self.text = self.text[idx+1:]
		else:
			ident = "|"
			size = len(self.text)
			idx = []
			while True:
				idx.append(self.text.find(ident))
				if idx[-1] > len(self.text) / 2 or idx[-1] < 0:
					head = self.text.find('.') + 1 # match SCENE I.
					tail = idx[-1] - 25
					self.text = self.text[head:tail]
					break
				self.text = self.text[idx[-1]+1:]
		self.text = get_full_name(self.name) + self.text
	def write_meta(self):
		with open(self.meta_path, "a") as file:
			file.write("{\n    ")
			file.write("\"id\" : "+str(self.id)+",\n    " )
			file.write("\"name\" : ")
			file.write("\""+self.name+"\"\n")
			file.write("},\n")
	def write_raw(self):
		sentence_end = [".","?","!"]
		interval = ["\n"," "]
		if self.is_poem:
			sentence_end.append("\n")

		if len(self.manifest) != 0:
			offset = self.manifest[2][-1]+self.manifest[1]
		else: 
			offset = 0
		self.manifest = [self.id,offset,[0]]

		offset = 0 # sentence[0] = passage[offset]
		if self.is_poem:
			sentence_end.append("\n")
		in_sentence = False
		in_interval = False
		with open(self.raw_path,"a") as file:
			for c in self.text:
				# another sentence
				if c in sentence_end and in_sentence: 
					offset += 2 # \n == \r\n
					if not c == "\n":
						file.write(c)
						offset += 1
					file.write("\n")
					self.manifest[2].append(offset)
					in_sentence = False
					in_interval = False				
				# token interval
				elif c in interval and in_sentence and not in_interval: 
					offset += 1
					file.write(" ")
					in_interval = True
				# non-symbol
				elif ord(c)>=48 and ord(c)<=57 or ord(c)>=65 and ord(c)<=90 or ord(c)>=97 and ord(c)<=122:
					offset += 1
					in_sentence = True
					file.write(c)
					in_interval = False
				# flush symbol
				elif not c in sentence_end+interval:
					offset += 1
					file.write(c)
					in_sentence = True
			if in_sentence:
				offset+=2
				file.write('\n')
				self.manifest[2].append(offset)
	def write_manifest(self):
		with open(self.manifest_path, "a") as file:
			file.write("{\n    ")
			file.write("\"id\" : "+str(self.manifest[0])+",\n    " )
			file.write("\"offset\" : "+str(self.manifest[1])+",\n    " )
			file.write("\"sentences\" : ")
			file.write("[")
			for j in self.manifest[2][:-1]:
				file.write(str(j)+",")
			file.write(str(self.manifest[2][-1]))
			file.write("]\n")
			file.write("},\n")
	def tokenize(self):
		tokens = ["$"]
		sentence_end = [".","?","!"]
		if self.is_poem:
			sentence_end.append("\n")
		low_letter = [97,122]
		up_letter = [65,90]
		number = [48,57]
		number_map = ["zero","one","two","three","four","five","six","seven","eight","nine"]
		reading_word = False
		for c in self.text:
			if c in sentence_end:
				self.tokens.append("E")
				reading_word = False
			elif ord(c) <= number[1] and ord(c) >= number[0]:
				if not self.is_poem:
					self.tokens.append(number_map[int(c)])
				reading_word = False
			elif ord(c) <= low_letter[1] and ord(c) >= low_letter[0]:
				if reading_word:
					self.tokens[-1] = self.tokens[-1]+c;
				else:
					reading_word = True
					self.tokens.append(c)
			elif ord(c) <= up_letter[1] and ord(c) >= up_letter[0]:
				lower_c = chr(ord(c) + 32)
				if reading_word:
					self.tokens[-1] = self.tokens[-1]+lower_c;
				else:
					reading_word = True
					self.tokens.append(lower_c)
			else:
				reading_word = False
		tokens.append("$")
	def write_token(self):
		with open(self.token_path,"a") as file:
			file.write("\n$$ "+self.name+" $$\n")
			ctrl = ["$"]
			end = ["E"]
			tokener = " "
			in_interval = False
			for token in self.tokens:
				if not token in ctrl+end:
					if len(token) >= 3:
						file.write(token+tokener)
						in_interval = False
				elif not in_interval:
					file.write('\n')
					in_interval = True
	def free(self):
		self.text = ""
		self.tokens = []

if __name__ == '__main__':
	# file path
	tokenizer = Tokenizer('/data/raw_token','/data/text','/data/text_manifest','/data/tokenizer_meta')
	# poetry in 2nd depth
	addition_list = [url_object(name,"http://shakespeare.mit.edu/Poetry/"+name+".html") for name in ["LoversComplaint","RapeOfLucrece","VenusAndAdonis","elegy"]]
	# traver other site with 3rd depth 
	books = Traverse("http://shakespeare.mit.edu/index.html")
	sections = []
	for book in books:
		sections += Traverse(book.url)
	sections += addition_list
	for section in sections:
		# get plain text
		raw = BeautifulSoup(urllib.urlopen(section.url))
		if is_valid_text(raw.get_text()):
			# write to file
			tokenizer.run(section.name, raw.get_text())
			tokenizer.free()

