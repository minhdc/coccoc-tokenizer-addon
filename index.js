const testAddon = require('./build/Release/coccoc-tokenizer-addon.node')
let h = new testAddon.HelloWrap("Minh")
console.log('hello: ',h.getUserName())

module.exports = testAddon