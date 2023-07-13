(function() {
  // iframeを作成します
  var iframe = document.createElement('iframe');

  // iframeの属性を設定します
  iframe.src = 'http://twitter.com';
  iframe.width = '500px';
  iframe.height = '300px';

  // iframeをbodyの末尾に追加します
  document.body.appendChild(iframe);
})();
