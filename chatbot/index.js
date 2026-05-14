function toggleChat() {
    var win = document.getElementById('chatWindow');
    var isOpen = win.classList.contains('open');
    win.classList.toggle('open');

    if (!isOpen) {
        var chatbox = document.getElementById('chatbox');
        if (chatbox.children.length === 0) {
            addMsg('bot', 'Hello! Welcome to City College. How can I help you?');
        }
        document.getElementById('userInput').focus();
    }
}

function addMsg(type, text) {
    var chatbox = document.getElementById('chatbox');
    var div = document.createElement('div');
    div.className = 'msg ' + type;
    div.textContent = (type === 'user' ? 'You: ' : 'Bot: ') + text;
    chatbox.appendChild(div);
    chatbox.scrollTop = chatbox.scrollHeight;
}

function sendMessage() {
    var input = document.getElementById('userInput');
    var message = input.value.trim();
    if (!message) return;

    addMsg('user', message);

    var lower = message.toLowerCase();
    var response = '';

    if (lower.includes('hello') || lower.includes('hi')) {
        response = 'Hello! Welcome to our college.';
    } else if (lower.includes('courses')) {
        response = 'We offer BCA, BBA, MCA and MBA courses.';
    } else if (lower.includes('timing')) {
        response = 'College timing is 9 AM to 5 PM.';
    } else if (lower.includes('library')) {
        response = 'Library is on the 2nd floor.';
    } else if (lower.includes('bye')) {
        response = 'Thank you! Visit again.';
    } else {
        response = "Sorry, I don't understand. Try asking about courses, timing, or library.";
    }

    setTimeout(function() {
        addMsg('bot', response);
    }, 300);

    input.value = '';
}
