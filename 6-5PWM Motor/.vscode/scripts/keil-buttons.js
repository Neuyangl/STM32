document.addEventListener('DOMContentLoaded', () => {
    // 找到标题栏右侧的按钮容器
    const titleBarRight = document.querySelector('.titlebar-right');
    if (!titleBarRight) return;

    // 创建编译按钮
    const buildBtn = document.createElement('div');
    buildBtn.className = 'action-item';
    buildBtn.innerHTML = '<a class="action-label codicon codicon-build" title="Keil 编译"></a>';
    buildBtn.onclick = () => {
        // 触发Keil Assistant的编译命令
        vscode.commands.executeCommand('keil-assistant.build');
    };
    titleBarRight.insertBefore(buildBtn, titleBarRight.firstChild);

    // 创建重新编译按钮（可选）
    const rebuildBtn = document.createElement('div');
    rebuildBtn.className = 'action-item';
    rebuildBtn.innerHTML = '<a class="action-label codicon codicon-refresh" title="Keil 重新编译"></a>';
    rebuildBtn.onclick = () => {
        vscode.commands.executeCommand('keil-assistant.rebuild');
    };
    titleBarRight.insertBefore(rebuildBtn, titleBarRight.firstChild);
});