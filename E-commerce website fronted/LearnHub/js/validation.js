// ===== Form Validation =====
document.addEventListener('DOMContentLoaded', () => {
    const loginForm = document.getElementById('loginForm');
    const signupForm = document.getElementById('signupForm');
    const loginToggle = document.getElementById('loginToggle');
    const signupToggle = document.getElementById('signupToggle');
    const switchToSignup = document.getElementById('switchToSignup');
    const switchToLogin = document.getElementById('switchToLogin');
    
    // Form Toggle
    if (loginToggle && signupToggle) {
        loginToggle.addEventListener('click', () => {
            showLoginForm();
        });
        
        signupToggle.addEventListener('click', () => {
            showSignupForm();
        });
    }
    
    if (switchToSignup) {
        switchToSignup.addEventListener('click', (e) => {
            e.preventDefault();
            showSignupForm();
        });
    }
    
    if (switchToLogin) {
        switchToLogin.addEventListener('click', (e) => {
            e.preventDefault();
            showLoginForm();
        });
    }
    
    // Login Form Validation
    if (loginForm) {
        loginForm.addEventListener('submit', (e) => {
            e.preventDefault();
            
            const email = document.getElementById('loginEmail').value;
            const password = document.getElementById('loginPassword').value;
            
            let isValid = true;
            
            // Email validation
            if (!validateEmail(email)) {
                showError('loginEmailError', 'Please enter a valid email');
                isValid = false;
            } else {
                clearError('loginEmailError');
            }
            
            // Password validation
            if (password.length < 6) {
                showError('loginPasswordError', 'Password must be at least 6 characters');
                isValid = false;
            } else {
                clearError('loginPasswordError');
            }
            
            if (isValid) {
                handleLoginSubmit(email, password);
            }
        });
    }
    
    // Signup Form Validation
    if (signupForm) {
        signupForm.addEventListener('submit', (e) => {
            e.preventDefault();
            
            const firstName = document.getElementById('signupFirstName').value;
            const lastName = document.getElementById('signupLastName').value;
            const email = document.getElementById('signupEmail').value;
            const password = document.getElementById('signupPassword').value;
            const confirmPassword = document.getElementById('signupConfirmPassword').value;
            const agreeTerms = document.getElementById('agreeTerms').checked;
            
            let isValid = true;
            
            // First name
            if (!firstName.trim()) {
                showError('firstNameError', 'First name is required');
                isValid = false;
            } else {
                clearError('firstNameError');
            }
            
            // Last name
            if (!lastName.trim()) {
                showError('lastNameError', 'Last name is required');
                isValid = false;
            } else {
                clearError('lastNameError');
            }
            
            // Email
            if (!validateEmail(email)) {
                showError('signupEmailError', 'Please enter a valid email');
                isValid = false;
            } else {
                clearError('signupEmailError');
            }
            
            // Password
            if (password.length < 8) {
                showError('signupPasswordError', 'Password must be at least 8 characters');
                isValid = false;
            } else {
                clearError('signupPasswordError');
            }
            
            // Confirm password
            if (password !== confirmPassword) {
                showError('confirmPasswordError', 'Passwords do not match');
                isValid = false;
            } else {
                clearError('confirmPasswordError');
            }
            
            // Terms
            if (!agreeTerms) {
                showError('termsError', 'You must agree to the terms');
                isValid = false;
            } else {
                clearError('termsError');
            }
            
            if (isValid) {
                handleSignupSubmit(firstName, lastName, email, password);
            }
        });
    }
    
    // Password visibility toggle
    document.querySelectorAll('.password-toggle').forEach(toggle => {
        toggle.addEventListener('click', function() {
            const input = this.previousElementSibling;
            const type = input.getAttribute('type') === 'password' ? 'text' : 'password';
            input.setAttribute('type', type);
            this.innerHTML = type === 'password' ? '<i class="fas fa-eye"></i>' : '<i class="fas fa-eye-slash"></i>';
        });
    });
    
    // Password strength indicator
    const signupPassword = document.getElementById('signupPassword');
    if (signupPassword) {
        signupPassword.addEventListener('input', () => {
            const password = signupPassword.value;
            const strengthBar = document.querySelector('.strength-bar');
            const strengthText = document.querySelector('.strength-text strong');
            
            let strength = 0;
            let text = 'Weak';
            let color = '#ef4444';
            
            if (password.length >= 8) strength++;
            if (/[a-z]/.test(password) && /[A-Z]/.test(password)) strength++;
            if (/[0-9]/.test(password)) strength++;
            if (/[^a-zA-Z0-9]/.test(password)) strength++;
            
            switch(strength) {
                case 4:
                    text = 'Very Strong';
                    color = '#10b981';
                    break;
                case 3:
                    text = 'Strong';
                    color = '#3b82f6';
                    break;
                case 2:
                    text = 'Medium';
                    color = '#f59e0b';
                    break;
                default:
                    text = 'Weak';
                    color = '#ef4444';
            }
            
            strengthBar.style.width = (strength * 25) + '%';
            strengthBar.style.backgroundColor = color;
            strengthText.textContent = text;
            strengthText.style.color = color;
        });
    }
});

function validateEmail(email) {
    const re = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    return re.test(email);
}

function showError(elementId, message) {
    const element = document.getElementById(elementId);
    if (element) {
        element.textContent = message;
    }
}

function clearError(elementId) {
    const element = document.getElementById(elementId);
    if (element) {
        element.textContent = '';
    }
}

function showLoginForm() {
    const loginForm = document.getElementById('loginForm');
    const signupForm = document.getElementById('signupForm');
    const loginToggle = document.getElementById('loginToggle');
    const signupToggle = document.getElementById('signupToggle');
    
    loginForm.classList.add('active');
    signupForm.classList.remove('active');
    loginToggle.classList.add('active');
    signupToggle.classList.remove('active');
}

function showSignupForm() {
    const loginForm = document.getElementById('loginForm');
    const signupForm = document.getElementById('signupForm');
    const loginToggle = document.getElementById('loginToggle');
    const signupToggle = document.getElementById('signupToggle');
    
    loginForm.classList.remove('active');
    signupForm.classList.add('active');
    loginToggle.classList.remove('active');
    signupToggle.classList.add('active');
}

function handleLoginSubmit(email, password) {
    // Simulate login
    console.log('Login attempt:', { email, password });
    showNotification('Login successful! Redirecting...', 'success');
    setTimeout(() => {
        window.location.href = 'dashboard.html';
    }, 1500);
}

function handleSignupSubmit(firstName, lastName, email, password) {
    // Simulate signup
    console.log('Signup attempt:', { firstName, lastName, email, password });
    showNotification('Account created successfully! Redirecting...', 'success');
    setTimeout(() => {
        window.location.href = 'dashboard.html';
    }, 1500);
}

function showNotification(message, type = 'success') {
    const notification = document.createElement('div');
    notification.className = `notification notification-${type}`;
    notification.innerHTML = message;
    notification.style.cssText = `
        position: fixed;
        top: 20px;
        right: 20px;
        padding: 15px 20px;
        background-color: ${type === 'success' ? '#10b981' : '#ef4444'};
        color: white;
        border-radius: 8px;
        z-index: 1000;
        animation: slideIn 0.3s ease-in-out;
        box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
    `;
    document.body.appendChild(notification);
    
    setTimeout(() => {
        notification.style.animation = 'slideOut 0.3s ease-in-out';
        setTimeout(() => notification.remove(), 300);
    }, 3000);
}