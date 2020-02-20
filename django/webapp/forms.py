from django import forms
from webapp.models import AuthUser
from webapp.models import dataMCU

class loginForm(forms.Form):
    username = forms.CharField(label="Username:",max_length=45, widget=forms.TextInput(attrs={'placeholder':'Username'}))
    password = forms.CharField(label="Password:",max_length=45, widget=forms.PasswordInput(attrs={'placeholder': 'Password'}))


class createAccountForm(forms.ModelForm):
    firstName = forms.CharField(
        required = 'True',
        label="First Name:",
        max_length=45, 
        widget=forms.TextInput(attrs={'placeholder': 'First name', 'autocomplete': 'off'})
    )
    lastName = forms.CharField(
        required = 'True',
        label="Last Name:",
        max_length=45, 
        widget=forms.TextInput(attrs={'placeholder': 'Last name', 'autocomplete': 'off'})
    )
    email = forms.CharField(
        required = 'True',
        label="E-mail:",
        max_length=100, 
        widget=forms.TextInput(attrs={'placeholder': 'hello@example.com'})
    )
    username = forms.CharField(
        required = 'True',
        label="Username:",max_length=45, 
        widget=forms.TextInput(attrs={'placeholder': 'Username', 'autocomplete': 'off'})
    )
    password = forms.CharField(
        required = 'True',
        label="Password:",
        max_length=45, 
        widget=forms.PasswordInput(attrs={'placeholder': 'Password', 'autocomplete': 'new-password'})
    )

    class Meta:
        model = AuthUser
        fields = ('username','password','email','firstName','lastName')

# class createDataForm(forms.ModelForm):
#     # mcu_no = forms.IntegerField(label="mcu_no")

#     # data_date = forms.DateTimeField()

#     # soil_moisture = forms.IntegerField(label="soil_moisture")

#     # soil_temp = forms.FloatField(label="soil_temp")

#     # temp = forms.FloatField(label="temp")

#     # humidity = forms.FloatField(label="humidity")

#     # light_reading = forms.IntegerField(label="light_reading")

#     # heat_index = forms.IntegerField(label="heat_index")

#     # battery_level = forms.IntegerField(label="battery_level")

#     class Meta:
#         model = dataMCU
#         fields = ['mcu_no','temp', 'humidity', 'soil_moisture', 'soil_temp', 'light_reading', 'heat_index', 'battery_lvl']