//JSON中没有Undefined类型
/*可以表示三种数据类型的值：
* 简单值
* 对象
* 数组
* JSON不支持变量、函数、或对象实例，就是一种表示结构化数据的格式。
*/

//简单值：
//5
//字符串必须用双引号表示
//"Hello world!"
//表示对象的方法,所有对象的属性必须加双引号""
/*{
	"name":"Greg",
	"age":29
}
{
	"name":"Greg",
	"age":29,
	"school":{
		"name":"Merrimack College",
		"location":"North Andover, MA"
	}
}
*/
//数组
//[25,"Amy",50,true]
//数组和对象可以结合起来

//********解析JSON
function readJSON(){
	//较早版本的浏览器使用
	//shim:Test.json;
	//早期的解析器使用eval()函数
	//现在JSON对象有方法parse()用来把json字符串解析成原生Javascripe的值
	var jsontext="\
	{\
		\"name\":\"Greg\",\
		\"age\":29,\
		\"school\":{\
			\"name\":[\"Merrimack College\",\"Xi'an University of Technolog\",\"Qinghua University\"],\
			\"location\":\"North Andover, MA\"\
		}\
	}";
	var book=JSON.parse(jsontext);
	console.log("输出book：");
	console.log(book);
	//加了函数（过滤器）
	var bookFilter = JSON.parse(jsontext,function(key,value){
		if(key == "school"){
			return "Social University";
		}
		else{
			return value;
		}
	});
	console.log("输出带过滤器的book：");
	console.info(bookFilter);
	//输出book的school属性的name属性
	console.info("输出book的school属性的name属性"+book.school.name);
	//输出book的school的name数组的第2个
	console.info("输出book的school的name数组的第2个"+book.school.name[1]);
}
//readJSON();
//*********把对象序列化为JSON
function writeJSON(){
	var book = {
			"name":"Greg",
			"age":29,
			"school":{
				"name":["Merrimack College","Xi'an University of Technolog"],
				"location":"North Andover MA"
			}
		};
	var jsonText = JSON.stringify(book);
	//输出对象转化的JSON
	console.log("输出对象转化的JSON");
	console.log(jsonText);
	//过滤
	var jsonTextFilter = JSON.stringify(book,["name","age"]);
	console.log("输出过滤的");
	console.log(jsonTextFilter);
	//输出带函数过滤的,第三个参数是格式控制
	var jsonTextFilterF= JSON.stringify(book,function(key,value){
		switch(key){
			case "age":
				return 18;
			case "location":
				return "L.A.";
			default:
				return value;
		}
	},"---");
	console.log("输出带函数过滤的");
	console.log(jsonTextFilterF);
	//对象可以加toJSON()方法
	var people={
		"name":"Amy",
		"age":20,
		toJSON:function(){
			return this.name;
		}
	};
	var jsonText1=JSON.stringify(people);
	console.log(jsonText1);	//Amy
}
writeJSON();
