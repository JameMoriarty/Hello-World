//在jsx文件中是使用js语法，用js返回输出html，写进方法里。
//和.vue文件中的写法差不多，但是是没有标签语言的部分
import '../assets/styles/footer.styl'

export default {
    render() {
        return (
            <div id="footer">
                <span>
                    Written by WenQ
                </span>
            </div>
        )
    }
}