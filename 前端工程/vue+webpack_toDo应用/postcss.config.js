//自动处理css属性的浏览器前缀
const autoprefixer = require('autoprefixer')

module.exports = {
    plugins: [
        autoprefixer()
    ]
}